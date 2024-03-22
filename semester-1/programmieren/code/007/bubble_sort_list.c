#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#define LENGTH 100

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
} Node;

Node *new_node(int data, Node *previous, Node *next)
{
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->previous = previous;
    new->next = next;

    return new;
}

Node *get_last_node(Node *n)
{
    if (n->next == 0)
        return n;
    return get_last_node(n->next);
}

Node *add_to_list(int s, Node *list)
{
    if (!list)
    {
        list = new_node(s, 0, 0);
        return list;
    }
    Node *last = get_last_node(list);
    last->next = new_node(s, last, last->next);

    return list;
}

Node *get_element_at(int id, Node *n, int depth)
{
    if (depth == id)
        return n;
    if (!n->next)
        return NULL;
    return get_element_at(id, n->next, depth + 1);
}

Node *delete_from_list(Node *db, Node *n)
{
    if (n->next)
        n->next->previous = n->previous;

    if (n->previous)
        n->previous->next = n->next;
    else
        db = n->next;
    free(n);

    return db;
}

Node *swap_with_next(Node *head, Node *n)
{
    if (!n->next)
        return head;

    Node *temp = n->next->next;

    // connect next with previous node
    n->next->previous = n->previous;
    if (n->previous)
        n->previous->next = n->next;
    else
        head = n->next;

    // connect n with next->next
    n->next->next = n;
    n->previous = n->next;
    n->next = temp;
    if (temp)
        temp->previous = n;

    return head;
}

//-----------------------------------------------------
bool sorted(Node *);
Node *__bubble_sort(Node *, Node *);
Node *bubble_sort(Node *);
Node *randomize(Node *, int);

int main()
{
    srand(time(0));
    Node *list = 0;
    list = randomize(list, 0);
    list->data = 100;
    up_hex(list, LENGTH);

    list = bubble_sort(list);
    up_hex(list, LENGTH);
    printf("\n%d", sorted(list));
}

Node *randomize(Node *n, int depth)
{
    if (depth == LENGTH)
        return n;

    int val = rand() % LENGTH + 1;
    return randomize(add_to_list(val, n), depth + 1);
}

Node *bubble_sort(Node *list)
{
    while (!sorted(list))
    {
        list = __bubble_sort(list, list);
    }

    return list;
}

Node *__bubble_sort(Node *head, Node *n)
{
    if (!n->next)
        return head;
    if (n->data > n->next->data)
    {
        head = swap_with_next(head, n);
    }
    if (!n->next)
        return head; // yeah, ALWAYS returning what you want to return could make sense
    return __bubble_sort(head, n->next);
}

bool sorted(Node *list)
{
    if (!list->next)
        return true;
    if (list->data > list->next->data)
        return false;

    return sorted(list->next);
}

//------------------------------------------------------------------------------------------

void __up_hex(Node *list, int index, int depth)
{
    if (!list)
    {
        printf("\nList is empty");
        return;
    }

    if (index == depth)
        return;
    printf("\nelement %3d: %20d %10x %10x %10x",
           index,
           list->data,
           list->previous,
           list,
           list->next);
    if (!list->next)
        return;
    return __up_hex(list->next, index + 1, depth);
}

void up_hex(Node *db, int depth)
{
    printf("\nelement      %20s %10s %10s %10s", "data", "previous", "current", "next");
    printf("\n---------------------------------------------------------------------------");
    __up_hex(db, 0, depth);
    printf("\n---------------------------------------------------------------------------\n");
}

//-----------------------------------------------------------------------------------------------------


int average(int a, int b) {
    return (int) (a + b) / 2;
}

Node *quick_sort(Node *list, int left, int right)
{
    if(left == right) {
        return list;
    }

    int i_left = left;
    int i_right = right;
    int median = average(left, right);

    while (i_left < i_right) {
        while (get_element_at(i_left, list, 0) < get_element_at(median, list, 0)) {
            i_left ++;
        }
        while (get_element_at(i_right, list, 0) > get_element_at(median, list, 0)) {
            i_right --;
        }

        // oops I need to re-implement the swap implementation
    }
}