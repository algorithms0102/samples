/******************************************************************************
 * HEAPSORT FEATURES:
 *     its running time is O(n * lgn)
 *     sort in place
 *     a data structure heap is in use
 * 
 * HEAP:
 *     The (binary) heap data structure is an array object that can be viewd as a 
 *     nearly compleate binary tree.
 *     index[0,	1,	2,	3,	4,	5,	6,	7,	8,	9]
 *     array[16,14,	10,	8,	7,	9,	3,	2,	4,	1]
 *     tree_graph:
 *                           16[0]
 *                        /         \
 *                   14[1]           10[2]
 *                  /     \         /     \
 *              8[3]       7[4] 9[5]       3[6]
 *              /  \       /
 *            2[7] 4[8]  1[9]
 *
 * HEAP FEATURES:
 *     In a max-heap A[PARENT[i]] >= A[i] Thus, the largest element in a 
 *     max-heap is stored at the root.
 *     the hight is lg n
 *
 ******************************************************************************/
#include <stdio.h>
#include <limits.h>
#define MAXLEN 10

void swap(int *a, int *b);
int parent(int i);
int left(int i);
int right(int i);
void min_heapify(int heap[], int i, int heap_size);
void max_heapify(int heap[], int i, int heap_size);
void build_min_heap(int heap[], int heap_size);
void build_max_heap(int heap[], int heap_size);
void heap_sort_asc(int heap[], int heap_size);
void heap_sort_desc(int heap[], int heap_size);
int heap_maximum(int heap[]);
int heap_minimum(int heap[]);
int heap_extract_max(int heap[], int heap_size);
int heap_extract_min(int heap[], int heap_size);
void heap_increase_key(int heap[], int i, int key);
void heap_decrease_key(int heap[], int i, int key);
void max_heap_insert(int heap[], int key, int heap_size);
void min_heap_insert(int heap[], int key, int heap_size);
/**
 * given a node with index i, return the index of its parent
 */
int parent(int i) {
    //return floor(i/2)
    //return i/2  integer division
    return i >> 1; //fast shift operation
}
/**
 * given a node with index i, return the idex of its left child
 */
int left(int i) {
    //return 2 * i + 1
    return  2 * i + 1;
}
/**
 * given a node with index i, return the idex of its right child
 */
int right(int i) {
    return 2 * (i + 1);
}

/**
 * the key procedure to maintaining the min-heap property
 * runs in O(lg n) time
 * proof: the running time of min_heapify on a subtree of size n
 * rooted at give node i is the theta(1) time to fix up the relationship
 * among the elements A[i], A[LEFT[i]] and A[RIGHT[i]], plus the time to 
 * run min_heapify on a subtree rooted at on of the children of the node i
 * the children's subtree is at most 2n/3---the worst case occurs when the 
 * last row of the subtree is exactly half full---and the running time of 
 * MIN-HEAPIFY can therefore be described by the recurrence:
 *  T(n) <= T(2n/3) + theta(1)
 * The solution to this recurrnce, by case 2 of the master theorem is :
 *  T(n) = O(lg n)
 */
void min_heapify(int heap[], int i, int heap_size) {
    int l = left(i);
    int r = right(i);
    int smallest;
    
    if (l < heap_size && heap[l] < heap[i]) {
        smallest = l;
    } else {
        smallest = i;
    }
    
    if (r < heap_size && heap[r] < heap[smallest]) {
        smallest = r;
    }
    
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        min_heapify(heap, smallest, heap_size);
    }
}
/**
 * runs in O(lg n) time
 * the key procedure to maintaining the max-heap property
 */
void max_heapify(int heap[], int i, int heap_size) {
    int l = left(i);
    int r = right(i);
    int largest;
    
    if (l < heap_size && heap[l] > heap[i]) {
        largest = l;
    } else {
        largest = i;
    }
    
    if (r < heap_size && heap[r] > heap[largest]) {
        largest = r;
    }
    
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        max_heapify(heap, largest, heap_size);
    }
}

/**
 * produce a min heap from an unordered array
 * runs in linear time
 */
void build_min_heap(int heap[], int heap_size) {
    for (int i = (heap_size >> 1) - 1; i >= 0; i--) {
        min_heapify(heap, i, heap_size);
    }
}

/**
 * produce a max heap from an unordered array
 * runs in linear time
 * proof:
 * key properties:
 *      an n-element heap has height floor(lg n) and at most ceil(n/2**(h+1))
 * nodes of any height h
 * see: page 135 on introduction to algorithms (2nd edition)
 */
void build_max_heap(int heap[], int heap_size) {
    //the elements in subarray heap[floor(heap_size/2) ...heap_size - 1] 
    //are all the leaves of the tree, so in a bottom-up manner,
    //we call max_heaify on heap[0...floor(heap_size/2) -1].
    //see tree_graph
    //floor(n/2) == n >> 1
    for (int i = (heap_size >> 1) - 1; i >= 0; i--) {
        max_heapify(heap, i, heap_size);
    }
}

/**
 * runs in O(n lg n) time
 * sorts an array in place in descending order
 */
void heap_sort_desc(int heap[], int heap_size) {
    build_min_heap(heap, heap_size);
    for (int i = heap_size - 1; i > 0; i--) {
        swap(&heap[0], &heap[i]);
        min_heapify(heap, 0, --heap_size);
    }
}

/**
 * runs in O(n lg n) time
 * sorts an array in place in ascending order
 */
void heap_sort_asc(int heap[], int heap_size) {
    build_max_heap(heap, heap_size);
    for (int i = heap_size - 1; i > 0; i--) {
        swap(&heap[0], &heap[i]);
        max_heapify(heap, 0, --heap_size);
    }
}
/**
 * on a min-heap
 */
int heap_minimum(int heap[]) {
    return heap[0];
}
/**
 * on a max-heap
 */
int heap_maximum(int heap[]) {
    return heap[0];
}
/**
 * extract the max elemnt in the heap
 * runs in O(lg n) time
 */
int heap_extract_max(int heap[], int heap_size) {
    if (heap_size < 1) {
        printf("error: heap underflow");
    }
    int max = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size = heap_size - 1;
    max_heapify(heap, 0, heap_size);
    return max;
}

int heap_extract_min(int heap[], int heap_size) {
    if (heap_size < 1) {
        printf("error: heap underflow");
    }
    int min = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size = heap_size - 1;
    min_heapify(heap, 0, heap_size);
    return min;
}

/**
 * increase the key of i
 * runs in O(lg n) time
 */
void heap_increase_key(int heap[], int i, int key) {
    if (key < heap[i]) {
        printf("error: new key is smaller than current key");
    }
    heap[i] = key;
    int parent_index = parent(i);
    while (i > 0 && heap[parent_index] < heap[i]) {
        swap(&heap[parent_index], &heap[i]);
        i  = parent_index;
    }
}


/**
 * decrease the key of i
 * runs in O(lg n) time
 */
void heap_decrease_key(int heap[], int i, int key) {
    if (key > heap[i]) {
        printf("error: new key is larger than current key");
    }
    heap[i] = key;
    int parent_index = parent(i);
    while (i > 0 && heap[parent_index] > heap[i]) {
        swap(&heap[parent_index], &heap[i]);
        i  = parent_index;
    }
}



void max_heap_insert(int heap[], int key, int heap_size) {
    heap[heap_size] = INT_MIN;
    heap_increase_key(heap, heap_size, key);
    heap_size += 1;
}

void min_heap_insert(int heap[], int key, int heap_size) {
    heap[heap_size] = INT_MAX;
    heap_decrease_key(heap, heap_size, key);
    heap_size += 1;
}


/**
 * inplace swap
 * this is an application of the property that a ^ a = 0
 * ^: exclusive-or
 */
void swap(int *a, int *b) {
    //assum initially:    *a = x,               *b = y
    *a = *a ^ *b;// step1 *a = x ^ y,           *b = y
    *b = *a ^ *b;// step2 *a = x ^ y,           *b =  x ^ y ^ y = x
    *a = *a ^ *b;// step3 *a = x ^ y ^ x = y,   *b = y
}

int main (int argc, const char * argv[])
{
    int heap[MAXLEN];
    for (int i = 0; i < MAXLEN; i++) {
        heap[i] = i;
    }
    for (int j = 0; j < MAXLEN; j++) {
        printf("%d ",heap[j]);
    }
    printf("\n");
    //heap sort
    heap_sort_desc(heap, MAXLEN);
    
    for (int j = 0; j < MAXLEN; j++) {
        printf("%d ",heap[j]);
    }
    printf("\n");
    
    printf("Hello, World!\n");
    return 0;
}
