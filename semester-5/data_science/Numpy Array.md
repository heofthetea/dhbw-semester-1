> n-[[Dimension|dimensional]] [[Vektor|vector]] 

- very effficient due to vectorized operations
- also they're [[Type|typed]]

### Eigenschaften
- **[[Dimension]]**: Number of axes
- **Axis**: The [[Dimension]] (1, 2, 3...) along which an operation is performed
	- -> can be used as keyword parameter in most operations 
	- hierarchy: column > row > "page" > ?? (4e is weird)
- **Shape**: how many elements in each [[Dimension]]?

> [!hint] Axis can e.g. be used too perform aggregating operations on [[Pandas Data Frame]] on a row (not column-wise) by specifying `axis=1`
## Indexing
### Indexing into multiple dimensions
- supports [[Python Slicing|list slicing]] as in normal python
- comma seperate:
```python
my_3d_array[3, 2:4, :]
```



### Boolean Indexing
- basically a [[filter Operation]]
- e.g.: 
```python
arr[arr > 5]
```

> [!hint] Difference to `np.where`: directly yields the actual _values_, whereas `np.where` yields an array of indices.
## Examples

### Add 10 to an entire list
```python
pyl = [1, 2, 3, 4, 5]
nparr = np.array(pyl)

# add 10 to every element
[x + 10 for x in pyl]
nparr + 10
```


### Change type of array
> [!hint] By default, mixed types are promoted to the higher detail (i.e. int -> float; there's really not a lot more)

```python
arr2 = arr1.astype(np.float64)
```