> Prune [[Pfad|paths]] of a [[Minimax]] in order to not have to calculate the full tree

- $\alpha$ and $\beta$ are the "[[Memory]]" from the previously explored tree
-  and  measure the **best possible** scores (of a [[Blatt|leaf]] position) for each player based on the previously explored tree:
	- $\alpha$ is best score so far for <span style="color:rgb(126, 198, 54)">maximizing</span> player 
	- $\beta$ is best score so far for <span style="color:rgb(245, 154, 35)">minimizing</span> player
- $\alpha$ ist "untere Schranke" für Bewertung ('max kann **mindestens** so gut sein")
- $\beta$ ist "obere Schranke" für Bewertung ("min kann **maximal** so gut sein")
	- sobald untere Schranke > obere Schranke => kann nicht sein, yeet
> [!hint] Breaking condition is _always_ $\alpha \gt \beta$.
> - $\alpha \gt \beta$ means: "the best path for <span style="color:rgb(126, 198, 54)">maximizing</span> player is better than <span style="color:rgb(245, 154, 35)">minimizing</span>'s best option so far"
>	- if it's <span style="color:rgb(245, 154, 35)">black</span>'s turn -> white had a better option available earlier -> won't take this path (failing low) 
>	- if it's <span style="color:rgb(126, 198, 54)">white</span>'s turn -> means black has a better option on this [[Pfad|path]] (= too good to be true)
>		- => the previously explored path is better for white (failing high)

> [!hint] $\alpha$ is always updated locally with values from children - $\beta$ is always passed down from the parent.
 
## pseudo-implementation
```python
def alpha_beta(pos, alpha, beta, depth, maximizing):
	if pos.game_over() or depth == 0
		return eval(pos)
	if maximizing:
		best_eval = -INFINITY
		for mv in pos.moves():
			leval = alpha_beta(pos + move, alpha, beta, depth - 1, !maximizing)
			best_eval = max(best_eval, leval)
			alpha = max(alpha, best_eval)
			if alpha > beta:
				break
	elif:
		best_eval = INFINITY
		for mv in pos.moves():
			leval = alpha_beta(pos + move, alpha, beta, depth - 1, !maximizing)
			best_eval = min(best_eval, leval)
			alpha = min(alpha, best_eval)
			if alpha > beta:
				break
```

## Optimization
- if better moves are evaluated first:
	- they lead to a higher evaluation => better $\alpha$ value at [[Wurzel|root]]
	- it's more likely that later branches will be worse (= lower $\beta$ value) and they will be pruned

## Notes
- there can never be a cut-off of a root move (because $\beta = \infty$ always (unless using [[PVS]] or sth with a smaller search window))
	- intuitive: We need to look at all moves at least once

> [!hint] The problem with Thunfsch then is: We can only start pruning at depth 2, which in chess means roughly $40^{2}$ sub-trees are always visited
## Gekritzel
- annotiert mit $\alpha$/$\beta$  werten
![[Pasted image 20251015153455.png]]
### Beispiel aus https://www.youtube.com/watch?v=l-hh51ncgDI&t=221s
![[Pasted image 20251015153840.png]]

![[Pasted image 20251015132209.png]]
