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


int a[10000000];
int main (int argc, const char * argv[])
{
    int n = 0;
    int i = 0;
    while (scanf("%d", &a[n]) != EOF)
        n++;

    quick_sort(a, 0, n-1);

    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    return 0;
}
