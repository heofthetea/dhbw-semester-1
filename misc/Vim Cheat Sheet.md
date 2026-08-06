


## Find and Replace
Format:
```
:[range(???)]s/old/new/{quantifier}
```

- quantifier:
	- `g` = all in line
	- `gc` = entire file, but prompt for each
- range:
	- `%` = entire file

### example
- prompt for every occurence in file (most useful):

```
:%s/foo/bar/gc
```

## Terminal
- `:terminal`

> [!hint] opens in WINDOW -> `ctrl+w ctrl+w` toggles between windows

