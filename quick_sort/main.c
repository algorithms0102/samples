//
//  main.c
//  quick_sort
//
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
int quick_sort(int array[], int p, int r);
int partition(int array[], int p, int q);

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


int main (int argc, const char * argv[])
{

    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = 100 - i;
    }
    quick_sort(array, 0, 99);
    for ( int i = 0; i < 100; i++) {
        printf("%d ", array[i]);
    }

    printf("Hello, World!\n");
    return 0;
}

