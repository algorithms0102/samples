//
//  main.c
//  counting_sort
//
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
int counting_sort(int array[], int n, int k);

int counting_sort(int array[], int n, int k) {
    int count_array[k];
    int sorted_array[n];
    int i = 0;
    int j = 0;
    for (; i < k; i++) {
        count_array[i] = 0;
    }
    for (; j < n; j++) {
        count_array[array[j]] = count_array[array[j]] + 1;
    }
    for (i = 1; i < k; i++) {
        count_array[i] = count_array[i] + count_array[i - 1];
    }
    for (j = n - 1; j >= 0; j--) {
        sorted_array[count_array[array[j]]-1] = array[j];
        count_array[array[j]] = count_array[j] - 1;
    }
    for (j = 0; j < n; j++) {
        array[j] = sorted_array[j];
    }

    
    return 0;
}

int main (int argc, const char * argv[])
{

    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = 100 - i;
    }
    counting_sort(array, 100, 101);
    
    for ( int i = 0; i < 100; i++) {
        printf("%d ", array[i]);
    }
    printf("Hello, World!\n");
    return 0;
}

