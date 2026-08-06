```
Host saturn
    HostName 141.31.112.48
    ProxyJump dhbw-login
    User inf23123
    RemoteCommand export HOME=/home.local/tmpuserhome/inf23123; cd ~; exec /bin/bash
    RequestTTY yes

Host dhbw-login
    HostName login.dhbw-stuttgart.de
    User inf23123
```

