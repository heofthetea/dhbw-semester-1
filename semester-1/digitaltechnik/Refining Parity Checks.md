> [!info] Allows to pin down the exact location of an error by finding out its column and its row


- Query specific groups for Errors
- Each [[Parity]] Check limits the scope of where an error could be located
#### 1. uneven Indices
[[Parity|Parity Bit]] at index $1$
- if Error detected: we know it has to be in an uneven position
- if not: either _no_ Error, _or_ Error in an even Position

#### 2. bits on right side
 $i\ mod \ 4 \in \set{2, 3}$ 
[[Parity|Parity Bit]] at index $2$

#### 3. uneven rows
$i\ mod\ 8 \in \set{4, 5, 6, 7}$
[[Parity|Parity Bit]] at index $4$

#### 4. bottom 2 rows
$i \geq 8$
[[Parity|Parity Bit]] at index $8$

==> [[Place Redundant Bits in Positions with Powers of 2]]

### Pinpoint no-error state
Set bit at index $0$ so that [[Parity]] of entire block is _even_
- if even number of errors happen:
	- Receiver _knows_ Errors must have happened due to previous Parity checks
	- Since bit at $0$ is even, that implies that an even number of errors occured
