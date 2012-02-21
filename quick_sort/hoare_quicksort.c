//
//  main.c
//  quick_sort
//
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b); 
int quick_sort(int array[], int p, int r);
int partition(int array[], int p, int q);

/**
 * inplace swap
 * this is an application of the property that a ^ a = 0
 * ^: exclusive-or
 */
void swap(int *a, int *b) {
    //assum initially:    *a = x,               *b = y
    *a = *a ^ *b;// step1 *a = x ^ y,           *b = y
    *b = *a ^ *b;// step2 *a = x ^ y,           *b =  x ^ y ^ y = x
    *a = *a ^ *b;// step3 *a = x ^ y ^ x = y,   *b = y
}

int quick_sort(int array[], int p, int r) {
    if (p < r) {
        int q = partition(array, p, r);
        quick_sort(array, p, q-1);
        quick_sort(array, q+1, r);
    }
    return 0;
}

int partition(int array[], int p, int q) {
    int x = array[p];
    while (p < q) {
        while (p < q && array[q] >= x) q--;
        if (p < q) swap(&array[p], &array[q]);
        while (p < q && array[p] <= x) p++;
        if (p < q) swap(&array[p], &array[q]);
    }
    return p;
}


int main (int argc, const char * argv[])
{

    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = 100 - i;
    }
    for ( int i = 0; i < 100; i++) {
        printf("%d ", array[i]);
    }
    printf("Hello, World!\n");
    quick_sort(array, 0, 99);
    for ( int i = 0; i < 100; i++) {
        printf("%d ", array[i]);
    }

    printf("Hello, World!\n");
    return 0;
}

