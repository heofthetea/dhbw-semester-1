> Prioritize Searches on moves on the Principal Variation

- requires a Record of Principal Variation -> usually obtained through [[Iterative Deepening]]
	- a simpler version is probably to simply do this _after_ move ordering => assume that [[Heuristik|heuristic]] ordering yields the best move

### Idea
1. Search the proposed best move (see Move Ordering) at Full window ($[\alpha, \beta] = [-\infty, \infty]$)
2. Search all other Moves at [[Null Window]]