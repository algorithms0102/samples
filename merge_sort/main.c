//
//  main.c
//  merge_sort
//
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
int merge(int array[], int p, int q, int r);
int merge_sort(int array[], int p, int r);



int merge(int array[], int p, int q, int r) {
	//compute length or the arrays to be merged
	int left_length = q - p + 1;	
	int right_length = r - q;
	//define two duplicated array
	int left_array[left_length + 1];
	int right_array[right_length + 1];
	//copy elements to duplicated array
	for (int i = 0; i < left_length; i++) {
		left_array[i] = array[p + i];
	}
	//
	left_array[left_length] = INT_MAX;
	
	//copy elements to duplicated array
	for (int i = 0; i < right_length; i++) {
		right_array[i] = array[q + 1 + i];
	}
	//
	right_array[right_length] = INT_MAX;

    int i = 0;
    int j = 0;
    
    for (int k = p; k <= r; k++) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
    }
    return 0;
}


int merge_sort(int array[], int p, int r) {
    if (p < r) {
		int q = p + ((r - p) >> 1);
		merge_sort(array, p, q);
		merge_sort(array, q + 1, r);
		merge(array, p, q, r);
    }
	return 0;
}
int main (int argc, const char * argv[])
{

    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = 100 - i;
    }
    merge_sort(array, 0, 99);
    for ( int i = 0; i < 100; i++) {
        printf("%d ", array[i]);
    }
    printf("Hello, World!\n");
    return 0;
}

