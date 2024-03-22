A _Node_ of a ·[[Doubly Linked List]] stores exactly three attributes:
1. The _data_ the Node holds
2. The Node's _predecessor_ list
3. The Node's _successor_ in the list

```python
typedef struct Node
{
	 Object *data;
	 Node *previous;
	 Node *next;
} Node;
```