/**
 * File Name:main.c
 * Description:
 * Create Date:15-02-2012
 * Last Modified:Wed 15 Feb 2012 07:08:53 PM CST
 *
 */

#include <stdio.h>


struct fib_heap_node {
    int key; //key
    int degree;
    fib_heap_node * left;
    fib_heap_node * right;
    fib_heap_node * parent;
    fib_heap_node * child;
    int marked; //whether node x has lost a child since the last time x was 
                //made the child of another child
} fib_heap_node;

struct fib_heap {
    int n;      // the number of nodes currently in heap
    fib_heap *min; // the root  of a tree containing the minimum key
    int max_degree; //the maximum degree of any node
    fib_heap_node * * cons;
} fib_heap;


fib_heap * new_fib_heap() {
    fib_heap * heap;
    heap = (fib_heap *)malloc(sizeof(fib_heap));
    
    if (heap == NULL) {
        printf
    }
}
