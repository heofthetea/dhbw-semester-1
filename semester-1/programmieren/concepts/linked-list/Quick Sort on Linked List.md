> Implementation of [[Quick Sort]] for the [[Doubly Linked List]] of the [[Shows Database]].

> The _most_ elegant way, by far, would have been to simply convert the [[Doubly Linked List|List]] into an [[Array]] of pointers to [[Node|Nodes]], sort that (see [[random_names.c]]) and convert back.
### Swap
Since in this case, the nodes get swapped around, there is a bunch of edge cases to consider:
1. Either one of the [[Node|Nodes]] being the [[Head]] or [[Tail]] of the [[Doubly Linked List]]
2. The two [[Node|Nodes]] are _adjacent_

To make this function a _tad_ less ugly, we will transform it into an [[oBdA]] case:
- Hereby, $a$ will _always_ be the node _further to the front_ of the List
- Thus, the cases *"a being the last element"* and _"b being the first element"_ cannot exist anymore, also there's only one way that the [[Node|Nodes]] could be adjacent ($a$ -> $b$)
```c
void swap(List *list, int index_a, int index_b)
{
	// makes sure that a is always the first node
    if (index_b < index_a)
    {
        int temp = index_a;
        index_a = index_b;
        index_b = temp;
    }
    Node *a = get_node_at(index_a, list);
    Node *b = get_node_at(index_b, list);

    if (!(a && b))
        return;

	//storing all environment nodes in temporary backups
    Node *a_previous = a->previous;
    Node *a_next = a->next;
    Node *b_previous = b->previous;
    Node *b_next = b->next;

	// Handling nodes on edge of list
    if(!a_previous)
        list->head = b;
    else 
	    a_previous->next = b;
    if(!b_next)
        list->tail = a;
    else 
	    b_next->previous = a;

	// Handling adjacent nodes
    if(index_a == index_b - 1) 
    {
        a->previous = b;
        b->next = a;
    } 
    // Handling regular cases
    else 
    {
        a_next->previous = b;
        b_previous->next = a;

        a->previous = b_previous,
        b->next = a_next;
    }
    
    b->previous = a_previous;
    a->next = b_next;
}
```


### Partitioning
I figured it is easier to work with _indices_ instead of actual elements.

_Note_: We want to sort _ascending_, thus the [[Strings#strcmp|strcmp]] function needs to return $x < 0$ for elements that are _in Order_. 

```c
Node *partition(List *list, int low, int high, int depth)
{
    // Node * pivot = get_element_at((int)list->length/2, list);
    int pivot = (int)(low + high) / 2;
    Node *node_at_pivot = get_node_at(pivot, list);
    int i_low = low;
    int i_high = high;

    while (i_low < i_high)
    {
        while (strcmp(get_node_at(i_low, list)->data->date, node_at_pivot->data->date) < 0)
            i_low++;
        Node *node_at_i_high = get_node_at(i_high, list);
        while (strcmp(get_node_at(i_high, list)->data->date, node_at_pivot->data->date) > 0)
            i_high--;
        list->current = node_at_pivot;
        swap(list, i_low, i_high);

        // adjust pivot
        if (i_low == pivot)
        {
            pivot = i_high;
        }
        else if (i_high == pivot)
        {
            pivot == i_low;
        }

        // increase iterators
        if (i_low < pivot)
            i_low++;
        if (i_high > pivot)
            i_high--;

        return pivot;
    }
}
```

### Sorting
The usual, trivial [[Recursion]] of [[Quick Sort]]:
```c
void quick_sort(List *list, int low, int high, int depth)
{
    if (low >= high)
        return list;

    int pivot = partition(list, low, high, depth);
    quick_sort(list, low, pivot - 1, depth + 1);
    quick_sort(list, pivot + 1, high, depth + 1);
}
```