## Element-wise
- do basica arithmetic with two [[Numpy Array|Numpy Arrays]]


## Comparison
```python
arr > 3
```

> [!warning] Compares for every element -> yields a [[Boolsche Menge|boolean]] [[Matrix]] that has the same dimensions as `arr`


## Concatenation
[[Matrix]]
- stack vertically: `a.vstack(b)`
- stack horizontally: `hstack`

## Search
- returns _indices_

```python
np.where(arr > 5)
```