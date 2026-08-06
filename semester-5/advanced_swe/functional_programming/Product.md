 > An [[Object]] $c$ with two [[Morphism|Projections]] $p, q$ s.t. for any other object $c'$ with two projections $p'$ and $q'$ there exists a [[Morphism]] transforming $p'$ and $q'$ into $p$ and $q$ respectively

- when talking about [[Type|Types]] the product of two types corresponds to a [[Rust Struct|Struct (Product Type)]]

> [!hint] The categorical Product $p \times q$ is a [[Bifunctor]], mapping $p$ and $q$ to the product $(p, q)$.

## Bifunctor
[[bimap]]
```haskell
instance Bifunctor PairProduct where
	bimap :: (a -> b) -> (b -> d) -> (a, b) -> (c ,d)
	bimap f g (x, y) = (f x, g y)
```
## Category Theoretical Construction
-> [[Universal Construction]]
### 1. Pattern
For the [[Product]] $c$ of two [[Object|Objects]] $a, b$ there must be one [[Morphism]] each (the factorizers $p, q$) going from $c$ to $a$ and $b$:

![[Pasted image 20251019171720.png]]

### 2. Order
An [[Object]] $C$ is higher-ordered than any Object $C'$ iff. there exists a **unique** [[Morphism]] $m: C' \longrightarrow C$ that can re-construct $C'$s factorizers $p'$ and $q'$ through [[Composition]]:

$$p' = p \circ m$$
$$q' = q \circ m$$

> [!hint]- $m$ factorizes the $p'$ and $q'$ (i.e. removes a common factor)
> Intuitively: The [[Natürliche Zahlen|natural numbers]]
> for $a = 2$ and $b = 3$, $c = 6$ and $c' = 24$
> -> then $p = \frac{6}{3} \mapsto 2$ and $q = \frac{6}{2} \mapsto 3$
> -> then also $p' = \frac{24}{\textbf{12}} \mapsto 2$ and $q' = \frac{24}{\textbf{8}} \mapsto 3$
> $m: c' \longrightarrow c := \frac{24}{4}$
> => The common factor of $4$ ($4\ |\ 12 \land 4\ |\ 8$) has been removed

![[Pasted image 20251019172030.png]]


> [!hint] This does not work in reverse because of the **unique** condition. Taking the common factor example; We can add infinitely many (bzw. in any case more than one) piece of information to $p$ and $q$ (or we cannot represent all possible cases encoded in $p$ and $q$) => they are not unique and thus it defines an actual [[Partial Order]].