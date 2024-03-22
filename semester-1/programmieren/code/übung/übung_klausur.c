#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct Guitarlol
{
    uint8_t num_strings;
    bool electric;
    char *brand;
} Guitarlol;

struct Test
{
    int *nums;
    int more_data;
    Guitarlol **guitars;
};

struct
{
    char name[32];
    int age;
    float salary;
} students[20];

// use
students[3].age[19];

struct Test *new_test(int num_guitars) {
    struct Test *t = (struct Test *) malloc(sizeof(struct Test));
    t->guitars = malloc(num_guitars * sizeof(Guitarlol *));

    for(int i = 0; i < num_guitars; i++) {
        t->guitars[i] = (Guitarlol *) malloc(sizeof(Guitarlol));
    }
    
    return t;
}

int main()
{
    struct Test *lol;
    lol = new_test(3);
    char temp[] = "Harley Benton";

    lol->guitars[0]->brand = temp;
    lol->guitars[2]->brand = "Ibanez";
    lol->guitars[2]->electric = true;

    return 0;
}