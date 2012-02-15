/**
 * File Name:main.c
 * Description:
 * Create Date:15-02-2012
 * Last Modified:Wed 15 Feb 2012 06:06:50 PM CST
 *
 */

#include <stdio.h>


struct fib_heap_node {
    int key;
    int degree;
    fib_heap_node * left;
    fib_heap_node * right;
    fib_heap_node * parent;
    fib_heap_node * child;
    int marked;
};

struct fib_heap {
    int key_num;
    fib_heap *min;
    int max_num_of_degree;
    fib_heap_node * * cons;
}


fib_heap * new_fib_heap() {
    fib_heap * heap;
    heap = (fib_heap *)malloc(sizeof(fib_heap));
    
    if (heap == NULL) {
        
    }
}
