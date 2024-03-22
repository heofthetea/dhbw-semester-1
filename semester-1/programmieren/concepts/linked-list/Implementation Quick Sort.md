[[Quick Sort]]
## Pseudo-Code
```python
def quick_sort(list, left, right):
	if(left >= right): # the given segment only contains one element (or is empty), thus is trivially sorted
		return list
	pivot = partition(list, left, right);
	
	quick_sort(list, left, pivot - 1) # left side
	quick_sort(list, pivot + 1, right) # right side


def partition(list, left, right):
	i_left = left # iteration variables, since left and right need to be kept 
	i_right = right
	pivot = (int) average(left, right) # set pivot to approximately the middle

	while i_left < i_right:
		while list[i_left] < list[pivot]: # iterate until element > pivot is found
			i_left += 1
		while list[i_right] > list[pivot]: # iterate until element < pivot
			i_right -= 1
		swap(list, i_left, i_right)
		
		# adjust for reaching pivot
		# happens because now, i_right must have gotten swapped with median
		if i_left == pivot:
			pivot = i_right
		elif i_right == pivot:
			pivot = i_left

		# increase iterators, idk why lol
		if i_left < pivot:
			i_left += 1
		if i_right > pivot:
			i_right -= 1

	return pivot

```


