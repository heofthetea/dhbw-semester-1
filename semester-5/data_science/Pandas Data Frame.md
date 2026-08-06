> Core Entity in [[Pandas]]

- 2-dimensional: Rows and Columns
- Zeilen sind [[Total Order|geordnet]]
- variable [[Dimension]] (whatever that means)
- Built on [[Numpy Array|Numpy]]

> [!hint] a Pandas Series is basically a 1D Data Frame.

> [!hint] Basically [[Instanz einer Relation]] mitsamt [[Schema einer Relation|Schema]]

# [[Object]] treatment

## Attribute
- `columns` -> [[Schema einer Relation]]
- `values` -> A [[Numpy Array]] of Feature Vectors
- `shape` -> [[Dimension|Dimension]] $(height, width)$
- `index` -> Produces a [[Intervall|Range]] that can be used to iterate over the set
## Operationen
### SQL-esque operations
- `df.iloc[n]` (wo $n$: [[Integer]]) -> Indexierung der $n$-ten Zeile ([[Relation]])
	- supports [[Python Slicing]] 
	-  zweidimensional:`df.iloc[lo_x:hi_x, lo_y:hi_y]` (1. Spalten, 2. Zeilen)
- `df[l]` (wo $l:\ list \subset [columns]$) -> equivalent zu `SELECT l FROM` [[SQL select]]
	- bsp: `df[["Attack", "Name"]]`
- `df.loc[predicate]`
	- **locate** all [[Tupel|tuples]] according to `predicate` (see [[Filtering a Data Frame]])

> [!hint] using `loc`/`iloc` over `df[]` indexing is an [[Monoid|monoidal]] operation -> it guarantees to preserve the [[Type]] of the frame, and doesn't accidentally produce a Series

#### update
```python
df.loc[df["column_1"] == "value_1", "col_to_change"] = "new value"
```

### Methods
- `head()` -> View rows 
- `df.sort_values` -> [[Sortieren]] nach [[Attribut]]
- `describe` -> [[Lagemaße]] ausgeben
- `info` -> View the [[Schema einer Relation|Schema]] of the dataframe (including [[Type|types]])
- `dropna` -> Drop ANY [[Tupel|tuple]] that contains any [[NaN]] values
	- alternative: `fillna(dict[column -> default])` -> Replaces [[NaN]] values as by the dict

ACH DIGGA ICH HAB KEINEN BOCK MEHR ES IST SO LANGWEILIG HOLY SHIT

# Indexing
```python
df["column"]
#or:
df[0]
```
- singular column

```python
df[["column1", "column2"]]
```
- view of two columns

> [!warning] Notice the double braces
