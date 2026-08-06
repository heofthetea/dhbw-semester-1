### Constraints
- [[NAT#Symmetric NAT|Symmetric NAT]]: NAS is not available from the outside
- DSM: fucking difficult to work with  because it can't just behave like a regular linux

## Solution
### 1. Use Cloudflare
- that allows for automated DNS-01 challenges 
- Generally better UI than hostinger lel

### 2. Blatantly steal someone's github gist
> [!warning] Beware that all scripts need to be ran as root - otherwise DSM complains becase it's stupid

- see here
https://gist.github.com/bergelfs/5d6484a713a4661683aa8f0c0a6b4d4d


## Commands
### Certificate renewal
```bash
/bin/certbot renew --post-hook "/volume1/system/letsencrypt/import_certs.sh"
```

> [!warning] sudo