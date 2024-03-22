#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define LEN_SUPPORT_ACTS 64

typedef struct
{
    char date[17];
    char venue[20];
    char headliner[64];
    char support_acts[LEN_SUPPORT_ACTS];

} Show;

typedef struct Node
{
    Show *data;
    struct Node *next;
    struct Node *previous;
} Node;

typedef struct List
{
    int length;
    Node *head;
    Node *current;
    Node *tail;
} List;

Show *show_from_console();
Show *show_from_row(char *row);
void manual_entry(List *db);
void read_text_file(List *db);
void delete_from_input(List *db);
void write_text_file(List *db);
int index_in_list(List *list, Node *n);
void up_hex(List *db);
void print_datasets(List *db);
void render_menu();
void swap(List *list, int a, int b);
void locate_endofstring_at_the_fucking_end_of_the_fucking_string(char *str, size_t len_str);
void quick_sort(List *list, int low, int high, int depth);
Node *partition(List *list, int low, int high, int depth);
