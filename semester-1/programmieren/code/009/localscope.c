#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

int main()
{
    test();
}

void test() {
    int a = 25;
    int arr[10];

    for(int i = a; i < a + 10; i++){
        arr[i - a] = i;
    }

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("\n%d", arr[i]);
    }
}
