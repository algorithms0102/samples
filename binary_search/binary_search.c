/**
 * File Name:binary_search.c
 * Description:
 * Create Date:08-02-2012
 * Last Modified:Wed 08 Feb 2012 07:15:30 PM CST
 *
 */

#include <stdio.h>

int binary_search(int array[], int n, int value) {
	int left = 0;
	int right = n-1;

	while (left <= right) {
		int middle = left + ((right - left) >> 1);
		if (array[middle] > value) {
			right = middle - 1;
		} else if (array[middle] < value) {
			left = middle + 1;
		} else {
			return middle;
		}
	}
	return -1;
}


int main() {
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("%d\n", binary_search(array,10,3));
	return 0;
}
