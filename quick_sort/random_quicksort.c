//
//  main.c
//  quick_sort
//
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int quick_sort(int array[], int p, int r);
int partition(int array[], int p, int q);
int random_int(int low, int high);
int random_partition(int array[], int p, int q);
void swap(int *a, int *b); 

int quick_sort(int array[], int p, int r) {
    if (p < r) {
        int q = random_partition(array, p, r);
        quick_sort(array, p, q-1);
        quick_sort(array, q+1, r);
    }
    return 0;
}

int partition(int array[], int p, int q) {
    int x = array[p];
    int i = p;
    for (int j = p + 1; j <= q; j++) {
        if (array[j] <= x) {
            i = i + 1;
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            
        }
    }
    int tmp = array[p];
    array[p] = array[i];
    array[i] = tmp;
    return i;
}

int random_int(int low, int high) {
    return (random() % (high - low + 1)) + low;
}

int random_partition(int array[], int p, int q) {
    int i = random_int(p, q);
    if(i != p) {
        swap(&array[i], &array[p]);
    }
    return partition(array, p, q);

}

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
