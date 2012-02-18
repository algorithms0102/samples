//
//  main.c
//  get_min_k_v1
//
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#define MAXLEN 10
#define K 5


void min_heapify(int array[], int i, int len);
void swap(int *a, int *b);
void build_min_heap(int array[], int len);
void heap_sort(int array[], int len);

void min_heapify(int array[], int i, int len) {
    int left = 2 * i + 1;
    int right = 2 * (i + 1);
    int smallest;
    
    if (left < len && array[left] < array[i]) {
        smallest = left;
    } else {
        smallest = i;
    }
    
    if (right < len && array[right] < array[smallest]) {
        smallest = right;
    }
    
    if (smallest != i) {
        swap(&array[i], &array[smallest]);
        min_heapify(array, smallest, len);
    }
}

void build_min_heap(int array[], int len) {
    for (int i = (len - 1) / 2; i >= 0; i--) {
        min_heapify(array, i, len);
    }
}

void heap_sort(int array[], int len) {
    build_min_heap(array, len);
    for (int i = len - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        min_heapify(array, 0, --len);
    }
}

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main (int argc, const char * argv[])
{
    
    int array[MAXLEN];
    for (int i = 0; i < MAXLEN; i++) {
        array[i] = i;
    }
    for (int j = 0; j < MAXLEN; j++) {
        printf("%d ",array[j]);
    }
    printf("\n");
    //heap sort
    heap_sort(array, MAXLEN);
    
    for (int j = 0; j < MAXLEN; j++) {
        printf("%d ",array[j]);
    }
    printf("\n");
    
    printf("Hello, World!\n");
    return 0;
}

