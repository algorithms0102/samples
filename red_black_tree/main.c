//
//  main.c
//  rb_tree
//
//  Created by chenjincai on 2/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int key_t;
typedef int data_t;

typedef enum color_t{
    RED = 0,
    BLACK = 1
} color_t;


typedef struct rb_node_t {
    struct rb_node_t *left, *right, *parent;
    key_t key;
    data_t data;
    color_t color;
} rb_node_t;

typedef struct rb_tree {
    struct rb_node_t *nil;
    struct rb_node_t *root;
} rb_tree;

static rb_tree *rb_new_tree();
static rb_node_t *rb_new_node(key_t key, data_t data);
static rb_node_t *rb_minimum(rb_tree *tree,rb_node_t *node);
static rb_node_t *rb_maximum(rb_tree *tree,rb_node_t *node);
static rb_node_t *rb_successor(rb_tree *tree,rb_node_t *node);
static rb_node_t *rb_left_rotate(rb_tree *tree, rb_node_t *node);
static rb_node_t *rb_right_rotate(rb_tree *tree, rb_node_t *node);
static rb_node_t *rb_insert_fixup(rb_tree *tree, rb_node_t *node);
static rb_node_t *rb_delete_fixup(rb_tree *tree, rb_node_t *node);

rb_node_t *rb_insert(rb_tree *tree, rb_node_t *node);
rb_node_t *rb_search(rb_tree *tree, key_t key);
rb_node_t *rb_delete(rb_tree *tree, rb_node_t *node);


int main (int argc, const char * argv[])
{
    int i = 0;
    int count = 100000;
    key_t key;
    rb_node_t *root = NULL;
    rb_tree *tree = rb_new_tree();
    
    
    
    
    
    srand(time(NULL));
    
    for (i = 1; i < count; i++) {
        key = rand() % count;
        rb_node_t *node = rb_new_node(key, i);
        if (rb_insert(tree,node) != tree->nil) {
            printf("[i = %d] insert key %d success!\n",i,key);
        } else {
            printf("[i = %d] insert key %d failed!\n",i,key);
            exit(1);
        }
        if (rb_search(tree, key) != tree->nil) {
            printf("[i = %d] search key %d success!\n", i, key); 
        }else {
            exit(1);
        }
        
        if (!(i%10)) {
            if (rb_delete(tree, node)) {
                printf("[i = %d] delete key %d success!\n", i, key);
            } else {
                printf("[i = %d] delete key %d failed!\n", i, key);
            }
        }
    }

    
    printf("Hello, World!\n");
    return 0;
}

static rb_tree *rb_new_tree() {
    rb_tree *tree = (rb_tree *)malloc(sizeof(struct rb_tree));
    if (!tree) {
        printf("mallock error!");
        exit(1);
    }
    rb_node_t *nil = rb_new_node(NULL, NULL);
    nil->color = BLACK;    //nil node has BLACK color
    tree->nil = nil;       //set tree nil
    tree->root = nil;       //init root as nil
    return tree;
}


static rb_node_t *rb_new_node(key_t key, data_t data) {
    rb_node_t *node = (rb_node_t *) malloc(sizeof(struct rb_node_t));
    if (!node) {
        printf("malloc error!");
        exit(1);
    }
    node->key = key;
    node->data = data;
    
    return node;
}

static rb_node_t *rb_minimum(rb_tree *tree,rb_node_t *x) {
    while (x->left != tree->nil) {
        x = x->left;
    }
    return x;
}

static rb_node_t *rb_maximum(rb_tree *tree,rb_node_t *x) {
    while (x->right != tree->nil) {
        x = x->right;
    }
    return x;
}

static rb_node_t *rb_successor(rb_tree *tree,rb_node_t *x) {
    rb_node_t *y;
    if (x->right != tree->nil) {
        return rb_minimum(tree, x->right);
    }
    y = x->parent;
    while (y != tree->nil && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

/**
 *   |                      |
 *   x                      y
 *  / \                    / \
 * A   y     ==>          x   C
 *    / \                / \
 *   B   C              A   B
 */

static rb_node_t *rb_left_rotate(rb_tree *tree, rb_node_t *x) {
    
    rb_node_t *y = x->right;    //set y
    x->right = y->left;         //turn y's left subtree into x's right subtree
    y->left->parent = x;        
    y->parent = x->parent;
    
    if (x->parent == tree->nil) {
        tree->root = y;
    } else {
        if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
    }
    
    y->left = x;
    x->parent = y;
    
    return tree->root;
}
/**
 *   |                      |
 *   y                      x
 *  / \                    / \
 * A   x     <==          y   C
 *    / \                / \
 *   B   C              A   B
 */
static rb_node_t *rb_right_rotate(rb_tree *tree, rb_node_t *x) {
    
    rb_node_t *y = x->left;    //set y
    x->left = y->right;         //turn y's left subtree into x's right subtree
    y->right->parent = x;
    y->parent = x->parent;
    
    if (x->parent == tree->nil) {
        tree->root = y;
    } else { 
        if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
    }
    
    y->right = x;
    x->parent = y;
    
    return tree->root;
}

rb_node_t *rb_insert(rb_tree *tree, rb_node_t *z) {
    rb_node_t *y = tree->nil;
    rb_node_t *x = tree->root;
    while (x != tree->nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    
    if (y == tree->nil) {
        tree->root = z;
    } else {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
    z->left = tree->nil;
    z->right = tree->nil;
    z->color = RED;
    rb_insert_fixup(tree, z);
    return tree->root;
}

static rb_node_t *rb_insert_fixup(rb_tree *tree, rb_node_t *z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            rb_node_t *y = z->parent->parent->right;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                
                if (z == z->parent->right) {
                    z = z->parent;
                    rb_left_rotate(tree, z);
                }
                
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rb_right_rotate(tree, z->parent->parent);
            }
        } else {
            rb_node_t *y = z->parent->parent->left;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rb_right_rotate(tree, z);
                }
                
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rb_left_rotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
    return tree->root;
}

static rb_node_t *rb_delete_fixup(rb_tree *tree, rb_node_t *x) {
    rb_node_t *w;
    while (x != tree->root && x->color == BLACK) {
        if (x == x->parent->left) {
            w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rb_left_rotate(tree, x->parent);
                w = x->parent->right;
            }
            
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rb_right_rotate(tree, w);
                    w = x->parent->right;
                }
                
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rb_left_rotate(tree, x->parent);
                x = tree->root;
            }
        } else {
            w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rb_right_rotate(tree, x->parent);
                w = x->parent->left;
            }
            
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    rb_left_rotate(tree, w);
                    w = x->parent->left;
                }
                
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rb_right_rotate(tree, x->parent);
                x = tree->root;
            }
            
        }
    }
    x->color = BLACK;
    return tree->root;
}

rb_node_t *rb_search(rb_tree *tree, key_t key) {
    rb_node_t *x;
    x = tree->root;
    while (x != tree->nil && key != x->key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

rb_node_t *rb_delete(rb_tree *tree, rb_node_t *z) {
    rb_node_t *x;
    rb_node_t *y;
    if (z->left == tree->nil || z->right == tree->nil) {
        y = z;
    } else {
        y = rb_successor(tree, z);
    }
    
    if (y->left != tree->nil) {
        x = y->left;
    } else {
        x = y->right;
    }
    
    x->parent = y->parent;
    
    if (y->parent == tree->nil) {
        tree->root = x;
    } else {
        if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
    }
    
    if (y != z) {
        z->key = y->key;
        z->data = y->data;
    }
    if (y->color == BLACK) {
        rb_delete_fixup(tree, x);
    }
    
    return y;
}