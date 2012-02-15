//
//  main.c
//  insertion_sort
//
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
int insertion_sort(int array[], int n);
int insertion_sort(int array[], int n) {
    for (int j = 1; j < n; j++) {
        int key = array[j];
        int i = j - 1;
        while (i >=0 && array[i] > key) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
    return 0;
}


int main (int argc, const char * argv[])
{

    int array[10];
    for (int i = 0; i < 10 ; i++) {
        array[i] = 10 - i;
        printf("%d ", array[i]);
    }
    
    insertion_sort(array, 10);
    
    for (int i = 0; i < 10 ; i++) {
        printf("%d ", array[i]);
    }

    
    printf("Hello, World!\n");
    return 0;
}

