> This shall serve as a brief overview of how to use the [[Redis]] CLI

(see [[Redis Installation]])

Enter the interactive shell with:
```
redis-cli
```

> [!hint] This CLI is case **insensitive**.
## [[CRUD]]
### Create an Entry
```
> SET key value
OK
```

#### With Expiration
- gives the [[Schlüssel|Key]] a Time to live

```
SETEX key <ttl> <value>
```

### Get an Entry
```
> GET key
value
```

> [!hint] is `(nil)` if the key doesn't exist
### Check for Existance
```
> EXISTS key
```

- returns [[Boolsche Menge|Boolean]] in numerischer darstellung;
	- `1` if key exists
	- `0` if not

### Delete an Entry
```
> DEL key
```

> [!hint] Returns as numeric [[Boolsche Menge|Boolean]] whether the deletion was successful

### Search for keys
```
KEYS <pattern>
```

## General
### Clear the Database
```
flushall
```



## Lists
> [!hint] This will be useful for the horsey example

