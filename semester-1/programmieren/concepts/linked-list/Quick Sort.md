[[Implementation Quick Sort]]
- Select index close to middle (this element is the _Pivot_)
- iterate through the list from left to right _and_ from right to left:
	- search for Elements _larger than Pivot_ located _left_ of Pivot
	- search for Elements _smaller than Pivot_ located _right_ of Pivot
	- once a pair is found: _swap_ those elements
	- when _Pivot_ is reached from one side: swap with _Pivot_ instead, however _keep Pivot as Pivot_, even if its index changed
- After iteration, all numbers _smaller_ than Pivot are located left of it, all _larger_ numbers right
- repeat recursively on 
![[quick_sort.png]]

_Runtime Complexity_: 
- _average case_: $O(\log_{2}(n))$ ([[Logarithmus Dualis]])
- _worst case_: Pivot is always the largest element --> Runtime Complexity of $O(n^{2})$ [[Runtime Bubble vs QuickSort]]


