/**
 * File Name:binary_search.c
 * Description:
 * Create Date:08-02-2012
 * Last Modified:Wed 08 Feb 2012 10:13:08 PM CST
 *
 */

#include <stdio.h>
/**
 * @target the element your want to search
 * @array {int} a sorted array in ascending order
 * @n     int  the number of elements in the array
 */
int binary_search(int target, int array[], int n) {
    int lower = 0;
    int upper = n-1;

    while (lower <= upper) {
        //use lower + (upper - lower) to prevent overflow
        int midpoint = lower + ((upper - lower) >> 1);
        if (target < array[midpoint]) {
            //lower.....target....midpoint....upper
            upper = midpoint - 1;
        } else if (target > array[midpoint]) {
            //lower....midpoint....target....upper
            lower = midpoint + 1;
        } else {
            return midpoint;
        }
    }
    return -1;
}


int main() {
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%d\n", binary_search(3, array, 10));
    return 0;
}
