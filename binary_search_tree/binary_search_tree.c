/**
 * File Name:binary_search_tree.c
 * Description:
 * Create Date:03-03-2012
 * Last Modified:Sun Mar  4 11:17:22 2012
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct BST_Node {
    int key;
    struct BST_Node *parent;
    struct BST_Node *left;
    struct BST_Node *right;
} BST_Node;

typedef struct BST {
    struct BST_Node *root;
} BST;

BST_Node *
BST_NewNode(int key)
{
    BST_Node * node = (BST_Node *)malloc(sizeof(struct BST_Node));

    if (node == NULL) {
        printf("malloc error\n");
        exit(1);
    }

    node->key = key;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BST *
BST_New()
{
   BST * tree = (BST *)malloc(sizeof(struct BST));

   if (tree == NULL) {
       printf("malloc error\n");
       exit(1);
   }

   tree->root = NULL;

   return tree;
}


void
BST_InorderWalk(BST_Node * node)
{
    if (node != NULL) {
        BST_InorderWalk(node->left);
        printf("%d\n", node->key);
        BST_InorderWalk(node->right);
    }
}

void
BST_Insert(BST *tree, BST_Node *node)
{
    BST_Node *y = NULL;
    BST_Node *x = tree->root;

    while (x != NULL) {
        y = x;
        if (node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == NULL) {
        tree->root = node;
    } else {
        if (node->key < y->key) {
            y->left = node;
        } else {
            y->right = node;
        }
    }
}

BST_Node *
BST_Search(BST_Node *node, int key)
{
    if (node == NULL | key == node->key) {
        return node;
    }

    if (key < node->key) {
        return BST_Search(node->left, key);
    } else {
        return BST_Search(node->right, key);
    }
}
/**
 * unrolling the recursion into a while loop, on most computers,
 * this version is more efficient
 */
BST_Node *
BST_IterativeSearch(BST_Node *node, int key)
{
    BST_Node *x = node;

    while (x != NULL && key != x->key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    return x;
}

BST_Node *
BST_Minimum(BST_Node *node)
{
    BST_Node *x = node;

    while (x->left != NULL) {
        x = x->left;
    }

    return x;
}

BST_Node *
BST_Maximum(BST_Node *node)
{
    BST_Node *x = node;

    while (x->right != NULL) {
        x = x->right;
    }

    return x;
}

BST_Node *
BST_Successor(BST_Node *node)
{
    if (node->right != NULL) {
        return BST_Minimum(node);
    }

    BST_Node *x = node;
    BST_Node *y = node->parent;

    while (y != NULL && node == y->right) {
        y = y->parent;
    }
    return y;
}

BST_Node *
BST_Predecessor(BST_Node *node)
{
    if (node->left != NULL) {
        return BST_Maximum(node);
    }

    BST_Node *x = node;
    BST_Node *y = node->parent;

    while (y != NULL && node == y->left) {
        y = y->parent;
    }
    return y;
}

BST_Node *
BST_Delete(BST *tree, BST_Node *node)
{
    BST_Node *y = NULL;
    BST_Node *x = NULL;

    //get the node y to splice out
    if (node->left == NULL || node->right == NULL) {
        y = node;
    } else {
        y = BST_Successor(node);
    }

    if (y->left != NULL) {
        x = y->left;
    } else {
        x = y->right;
    }

    if (x != NULL) {
        x->parent = y->parent;
    }
    if (y->parent == NULL) {
        tree->root = x;
    } else {
        if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
    }

    if (y != node) {
        node->key = y->key;
    }

    return y;
}

int
main()
{
    int key = 0;
    BST *bst = BST_New();
    while (scanf("%d", &key) != EOF) {
        BST_Node *node = BST_NewNode(key);
        BST_Insert(bst, node);
    }

    BST_InorderWalk(bst->root);

    return 0;

}
