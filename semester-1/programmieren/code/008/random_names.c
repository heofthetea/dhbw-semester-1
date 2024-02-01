#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define LENGTH 1000

bool sorted(char **);
int partition(char **, int, int);
void quick_sort(char **, int, int);

char *pointers[LENGTH];

int main()
{
    srand(time(NULL));
    populate_array(pointers);

    print_array(pointers, 100);
    printf("%d", sorted(pointers));

    // bubble_sort(pointers);
    quick_sort(pointers, 0, LENGTH - 1);
    print_array(pointers, 100);

    return 0;
}

void populate_array(char **pointers)
{
    for (int i = 0; i < LENGTH; i++)
    {
        int len_name = 5 + rand() % 8;

        pointers[i] = malloc(len_name + 1);
        pointers[i][0] = 'A' + rand() % 26;
        for (int j = 1; j < len_name; j++)
        {
            pointers[i][j] = 'a' + rand() % 26;
        }
        pointers[i][len_name] = 0;
    }
}

void print_array(char **arr, int until)
{
    printf("\n-------------------");
    for (int i = 0; i < until; i++)
    {
        printf("\n%-12s", arr[i]);
    }
    printf("\n-------------------");
}

//----------------------------------------------------------------------
void bubble_sort(char **arr)
{
    while (!sorted(arr))
    {
        for (int i = 0; i < LENGTH - 1; i++)
        {
            if (strcmp(arr[i], arr[i + 1]) > 0)
            {
                swap(arr, i, i + 1);
            }
        }
    }
}

void swap(char **arr, int a, int b)
{
    char *temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

bool sorted(char **arr)
{
    for (int i = 0; i < LENGTH - 1; i++)
    {
        if (strcmp(arr[i], arr[i + 1]) > 0)
            return false;
    }

    return true;
}

//----------------------------------------------------------------------

void quick_sort(char **arr, int left, int right)
{
    if (left >= right)
        return;

    int pivot = partition(arr, left, right);
    quick_sort(arr, left, pivot - 1);
    quick_sort(arr, pivot + 1, right);
}

int partition(char **arr, int left, int right)
{
    int pivot = average(left, right);
    int i_left = left;
    int i_right = right;

    while (i_left < i_right)
    {
        while (strcmp(arr[i_left], arr[pivot]) > 0)
            i_left++;
        while (strcmp(arr[i_right], arr[pivot]) < 0)
            i_right--;

        swap(arr, i_left, i_right);

        if (i_left == pivot)
            pivot = i_right;
        else if (i_right == pivot)
            pivot = i_left;

        if (i_left < pivot)
            i_left++;
        if (i_right > pivot)
            i_right--;
    }
    return pivot;
}


int average(int a, int b)
{
    return (int)(a + b) / 2;
}
