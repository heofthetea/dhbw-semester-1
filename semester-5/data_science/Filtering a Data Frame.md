[[filter Operation]], [[Pandas Data Frame]]
## Explicit Filter
```python
df[(df["column"] == "value")]
```

### And
```python
df[(df["column1"] == "value 1") & (df["column2"] == "value 2")]
```

> [!warning] Note that these are _bitwise_ syntax

## Datatype-specific operations
```python
df[df["column"].str.str_operation()]
```

### Alternative: Map
- say you have a function `is_xy(s: str) -> bool` that takes a [[String]] as parameter, but isn't a string operation
- Use the good old [[map Operation|map]] here:

```python
df["is_xy"] = df["column"].map(lambda v: is_xy(v))
```
-> now you can filter based on `df["is_xy"]`
## Negation

```python
df[~df[...filter]]
```
- use the tilde
## Grouping
- see [[SQL Group By]]
```python
df.groupby("column").aggregate_function()
```
### Custom Aggregate Function
```python
.agg(lambda x: ...)
```
