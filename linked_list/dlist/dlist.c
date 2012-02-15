/**
 * File Name:dlist.c
 * Description:
 * Create Date:02-11-2011
 * Last Modified:Sat Nov  5 15:53:07 2011
 * Author:7655cjc@gmail.com
 *
 */

#include <stdio.h>
#include "dlist.h"
#include "fatal.h"

typedef struct _DListNode {
	struct _DListNode *prev;
	struct _DListNode *next;

	void *data;
}DListNode;

struct _DList{
	DListNode *first
}DList;

static DListNode *dlist_node_create(void *data) {
	DListNode* node = malloc(sizeof(struct DListNode));

	if(node != NULL) {
		node->prev = NULL;
		node->next = NULL;
		node->data = data;
	}

	return node;
}

static void dlist_node_destroy(DListNode *node) {
	if(node != NULL) {
		node->prev = NULL;
		node->next = NULL;
		free(node);
	}

	return;
}

static DListNode *dlist_get_node(DList *thiz, size_t index, int fail_return_last) {
	
}
DList dlist_create(void) {
	DList *thiz = malloc(sizeof(struct DList));

	if(thiz != NULL){
		thiz->first = NULL;
	}
	
	return thiz;
}

DListRet dlist_insert(DList *thiz, size_t index, void *data) {
	
}

DListRet dlist_prepend(DList *thiz, void *data) {
	
}

DListRet dlist_print(DList *thiz, DListDataPrintFunc print) {
	DListRet ret = DLIST_RET_OK;
	DListNode *iter = thiz->first;

	while(iter != NULL) {
		print(iter->data);
		iter = iter->next;
	}

	return ret
}

