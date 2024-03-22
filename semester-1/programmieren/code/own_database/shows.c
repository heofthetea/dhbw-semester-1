#include "shows.h"

Node *new_node(Show *data, Node *previous, Node *next)
{
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->previous = previous;
    new->next = next;

    return new;
}

void add_to_list(Show *s, List *list)
{
    if (list->length == 0)
    {

        list->head = new_node(s, NULL, list->tail);
        list->tail = list->head;
    }
    else
    {
        list->tail->next = new_node(s, list->tail, list->tail->next);
        list->tail = list->tail->next;
    }
    list->length++;
}

Node *get_node_at(int id, List *list)
{
    if (list->length == 0)
        return NULL;
    list->current = list->head;
    int i = 0;
    while (list->current->next)
    {
        if (id == i)
            break;
        list->current = list->current->next;
        i++;
    }
    return list->current;
}

void delete_from_list(List *db, Node *n)
{
    if (n->next)
        n->next->previous = n->previous;

    if (n->previous)
        n->previous->next = n->next;
    else
        db->head = n->next;
    free(n);
    db->length--;
}

List *new_list()
{
    List *new = malloc(sizeof(List));
    new->length == 0;
    new->head, new->current, new->tail = 0;
}

int index_in_list(List *list, Node *n)
{
    list->current = list->head;
    int i = 0;
    while (list->current->next)
    {
        if (list->current == n)
            return i;
        list->current = list->current->next;
        i++;
    }
    return -1;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    char to_do[16];
    List *db = new_list();

    while (to_do)
    {
        render_menu();
        scanf("%s", &to_do);
        system("clear");
        fgetc(stdin); // for some reason this is important, otherwise the  console does madly weird shit

        if (!strcmp(to_do, "exit"))
            break;
        else if (!strcmp(to_do, "up_hex()"))
            up_hex(db);
        else if (!strcmp(to_do, "load"))
            read_text_file(db);
        else if (!strcmp(to_do, "all"))
            print_datasets(db);
        else if (!strcmp(to_do, "save"))
            write_text_file(db);
        else if (!strcmp(to_do, "delete"))
            read_text_file(db);
        else if (!strcmp(to_do, "test"))
            printf("\n%d", index_in_list(db, get_node_at(3, db)));
        else if (!strcmp(to_do, "sort"))
            quick_sort(db, 0, db->length - 1, 0);
        else if (!strcmp(to_do, "new"))
        {
            printf("Please enter the prompted attribute of your data set.\n\n");
            manual_entry(db);
        }
        else
            printf("\nHey Hannes, du Doedel, das ist keine valide Option!\n");
    }

    return 0;
}

void render_menu()
{
    printf("\nload: load .txt file");
    printf("\nnew: manually enter dataset");
    printf("\nall: show all datasets");
    printf("\nsave: write to .txt file");
    printf("\ndelete: delete element");
    printf("\nsort: sort the fucking array by the fucking date like i don't even give a fucking shit anymore this is literally the most bullshitted thing ever");

    printf("\n\nup_hex(): up_hex() as debugging tool");
    printf("\nexit: exit");
    printf("\n\n> ");
}

void manual_entry(List *db)
{
    Show *s = show_from_console();
    add_to_list(s, db);
}

// i need to find a different representation, strings are bullshit
Show *show_from_console()
{
    Show *temp = malloc(sizeof(Show));
    printf("enter date of show (as YYYY-MM-DD): ");
    // scanf("%s",&temp->date);
    fgets(temp->date, sizeof(temp->date), stdin);
    temp->date[strcspn(temp->date, "\n")] = 0;

    printf("enter venue of show: ");
    // scanf("%s", &temp->date);
    fgets(temp->venue, sizeof(temp->venue), stdin);
    temp->venue[strcspn(temp->venue, "\n")] = 0;

    printf("enter headliner: ");
    fgets(temp->headliner, sizeof(temp->headliner), stdin);
    temp->headliner[strcspn(temp->headliner, "\n")] = 0;

    printf("enter support acts (seperated by commata): ");
    fgets(temp->support_acts, sizeof(temp->support_acts), stdin);
    temp->support_acts[strcspn(temp->support_acts, "\n")] = 0;

    return temp;
}

void __print_datasets(Node *n, int index)
{
    if (!n)
    {
        printf("\nThere are no entries yet");
        return;
    }

    Show *s = n->data;
    printf("\nnode %3d: %-17s %-20s %-64s %-128s", index, s->date, s->venue, s->headliner, s->support_acts);
    if (n->next == 0)
        return;
    return __print_datasets(n->next, index + 1);
}

void print_datasets(List *db)
{
    printf("\n          %-17s %-20s %-64s %-128s", "date", "venue", "headliner", "support acts");
    printf("\n-----------------------------------------------------------------------------------------------------------------------------");
    __print_datasets(db->head, 0);
    printf("\n\n");
}

void __up_hex(Node *n, int index)
{
    if (!n)
    {
        printf("\nList is empty");
        return;
    }
    printf("\nelement %3d: %64s %10x %10x %10x",
           index,
           n->data->headliner,
           n->previous,
           n,
           n->next);
    if (!n->next)
        return;
    return __up_hex(n->next, index + 1);
}

void up_hex(List *db)
{
    printf("\nelement      %-64s %10s %10s %10s", "headliner", "previous", "current", "next");
    printf("\n-------------------------------------------------------");
    __up_hex(db->head, 0);
    printf("\n-------------------------------------------------------\n");
}

void delete_from_input(List *db)
{
    int temp_id;
    printf("\nEnter element index to delete: ");
    scanf("%d", &temp_id);
    Node *to_delete = get_node_at(temp_id, db);
    if (to_delete)
        delete_from_list(db, to_delete);
}

//--------------------------------------------------------------------------------------------------------------------------------------------

void write_text_file(List *db)
{
    // char filename[] = "db.txt";
    char filename[16];
    printf("Enter name of file to write to: ");
    scanf("%s", filename);
    fflush(stdin);

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file for writing: %s\n", filename);
        return;
    }

    db->current = db->head;
    int index = 0;

    while (db->current != NULL)
    {
        Show *s = db->current->data;
        // lul this really does the exact same as printing to console xd
        fprintf(file, "%-17s%-20s%-64s%-64s\n",
                s->date, s->venue, s->headliner, s->support_acts); // no spaces here
        db->current = db->current->next;
        index++;
    }

    fclose(file);
    printf("\nSuccessfully wrote %i lines to file %s!\n\n", index, filename);
}

Show *show_from_row(char *row)
{
    Show *new = malloc(sizeof(Show));
    int col = 0;
    strncpy(new->date, row + col, sizeof(new->date));
    col += sizeof(new->date);
    strncpy(new->venue, row + col, sizeof(new->venue));
    col += sizeof(new->venue);
    strncpy(new->headliner, row + col, sizeof(new->headliner));
    col += sizeof(new->headliner);
    strncpy(new->support_acts, row + col, sizeof(new->support_acts));

    locate_endofstring_at_the_fucking_end_of_the_fucking_string(new->date, sizeof(new->date));
    locate_endofstring_at_the_fucking_end_of_the_fucking_string(new->venue, sizeof(new->venue));
    locate_endofstring_at_the_fucking_end_of_the_fucking_string(new->headliner, sizeof(new->headliner));
    locate_endofstring_at_the_fucking_end_of_the_fucking_string(new->support_acts, sizeof(new->support_acts));

    return new;
}

// returns the updated linked list
void read_text_file(List *db)
{
    char filename[16];
    printf("Enter name of file to read from: ");
    scanf("%s", filename);
    fflush(stdin);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file for reading: %s\n", filename);
        return;
    }

    char row[256];

    while (!feof(file))
    {
        fgets(row, sizeof(row), file);
        Show *temp_show = show_from_row(row);
        add_to_list(temp_show, db);
    }

    delete_from_list(db, db->tail);
}

void locate_endofstring_at_the_fucking_end_of_the_fucking_string(char *str, size_t len_str)
{
    int i = len_str - 1;
    while (str[i] == ' ')
        i--;
    str[i + 1] = 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

// could this be done more elegantly? 100%. Do I care? fuck no.
// for example using an oBdA implementation? Again, fuck no.
void swap(List *list, int index_a, int index_b)
{

    if (index_a == index_b)
        return;
    // makes sure that index_a is always the smaller one
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

    Node *a_previous = a->previous;
    Node *a_next = a->next;
    Node *b_previous = b->previous;
    Node *b_next = b->next;

    if (!a_previous)
        list->head = b;
    else
        a_previous->next = b;
    if (!b_next)
        list->tail = a;
    else
        b_next->previous = a;

    if (index_a == index_b - 1)
    {
        a->previous = b;
        b->next = a;
    }
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

void quick_sort(List *list, int low, int high, int depth)
{
    if (low >= high)
        return list;

    int pivot = partition(list, low, high, depth);
    quick_sort(list, low, pivot - 1, depth + 1);
    quick_sort(list, pivot + 1, high, depth + 1);
}

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
