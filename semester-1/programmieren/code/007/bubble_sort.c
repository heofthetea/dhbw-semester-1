#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define LENGTH 50000

void randomize(int *);
void swap(int *, int, int);
void bubble_sort(int*);
void print_array(int *, int);
void quick_sort(int *, int, int);
bool sorted(int *);

int main()
{
    int numbers[LENGTH];
    // randomize(numbers);

    // double t1 = (double)clock() / CLOCKS_PER_SEC;
    // bubble_sort(numbers);
    // print_array(numbers, 1000);
    // double t2 = (double)clock() / CLOCKS_PER_SEC;
    // printf("\nsorted: %d\n", sorted(numbers));
    // printf("\ntime taken: %.5lf", t2 - t1);
    // printf("\n");

    //-------------------------------------------------
    printf("\n-------------------Quick Sort-----------------------------");
    randomize(numbers);
    
    double t3 = (double)clock() / CLOCKS_PER_SEC;
    quick_sort(numbers, 0, LENGTH);
    print_array(numbers, 1000);
    double t4 = (double)clock() / CLOCKS_PER_SEC;
    printf("\nsorted: %d\n", sorted(numbers));
    printf("\ntime taken: %.5lf", t4 - t3);
    printf("\n");

}

void print_array(int *arr, int until)
{
    printf("\n-------------------");
    for (int i = 0; i < until; i += 20)
    {
        printf("\n%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d",
               arr[i], arr[i + 1], arr[i + 2], arr[i + 3],
               arr[i + 4], arr[i + 5], arr[i + 6], arr[i + 7],
               arr[i + 8], arr[i + 9], arr[i + 10], arr[i + 11],
               arr[i + 12], arr[i + 13], arr[i + 14], arr[i + 15],
               arr[i + 16], arr[i + 17], arr[i + 18], arr[i + 19]);
    }
    printf("\n-------------------");
}

void randomize(int *numbers)
{
    srand(time(0));
    for (int i = 0; i < LENGTH; i++)
    {
        numbers[i] = rand() % 1000 + 1;
    }
}

void bubble_sort(int *numbers)
{
    while(!sorted(numbers)) {
        for(int i = 0; i < LENGTH - 1; i++) {
            if(numbers[i] > numbers[i + 1]) {
                swap(numbers, i, i + 1);
            }
        }
    }
}


bool sorted(int *arr) {
    for(int i = 0; i < LENGTH - 1; i++) {
        if(arr[i] > arr[i + 1]) return false;
    }

    return true;
}

void swap(int * arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


//-----------------------------------------------------------------------
int average(int a, int b)
{
    return (int)(a + b) / 2;
}


void quick_sort(int *arr, int left, int right)
{
    if (left >= right) return;
    // printf("hi me quick sort\n");

    int i_left = left;
    int i_right = right;
    int median = average(left, right);

    while (i_left < i_right)
    {
        while (arr[i_left] < arr[median])
        {
            i_left++;
        }
        while (arr[i_right] > arr[median])
        {
            i_right--;
        }

        swap(arr, i_left, i_right);

        if(i_left == median) 
            median = i_right;
        else if (i_right == median)
            median = i_left;
        
        if(i_left < median) 
            i_left ++;
        if(i_right > median)
            i_right --;

    }
    quick_sort(arr, left, median - 1);
    quick_sort(arr, median + 1, right);

}
// int partition(int *, int, int);


// void quick_sort(int *arr, int left, int right)
// {
//     if (left >= right) return;
//     int pivotIndex = partition(arr, left, right);
//     quick_sort(arr, left, pivotIndex - 1);
//     quick_sort(arr, pivotIndex + 1, right);
// }

// int partition(int *arr, int left, int right)
// {
//     int pivot = right;
//     int i = left - 1;

//     for (int j = left; j < right; j++)
//     {
//         if (arr[j] <= arr[pivot])
//         {
//             i++;
//             swap(arr, i, j);
//         }
//     }

//     swap(arr, i + 1, pivot);
//     return i + 1;
// }
