/**
 * File Name:list.c
 * Description:
 * Create Date:02-11-2011
 * Last Modified:Wed Feb 15 22:19:05 2012
 *
 */

#include <stdio.h>
#include "list.h"
#include "fatal.h"

struct _ListNode {
	ElementType element;
	Position next;
};

List  list_empty(List self) {
	if(self != NULL) {
		list_delete(self);
	}

	self = malloc(sizeof(struct _ListNode));
	if(self == NULL) {
		fatal_error("Out of memory!");
	}

	self->next = NULL;

	return self;
}

int list_is_empty(List self) {
	return self->next == NULL;	
}

int list_is_last(List self, Position p) {
	return p->next == NULL; 
}

Position list_find(List self, ElementType x) {
	Position p;

	p = self->next;
	while(p != NULL && p->element != x) {
		p = p->next;
	}

	return p;
}

void list_delete_element(List self, ElementType x) {
	Position p, tmp_cell;

	p = find_previous(self, x);
	if(!is_last(self, p)){
		tmp_cell = p->next;
		p->next = tmp_cell->next;
		free(tmp_cell);
	}	
}


Position list_find_previous(List self, ElementType x) {
	Position p;

	p = self;
	while(p->next != NULL && p->next->element != x) {
		p = p->next;
	}

	return p;
}

void list_insert(List self, ElementType x, Position p) {
	Position tmp_cell;

	tmp_cell = malloc(sizeof(struct _ListNode));
	if(tmp_cell == NULL) {
		fatal_error("Out of memory!");
	}

	tmp_cell->element = x;
	tmp_cell->next = p->next;
	p->next = tmp_cell;
}


void list_delete(List self) {
	Position p, tmp_cell;

	p = self->next;
	self->next = NULL;
	while(p != NULL) {
		tmp_cell = p->next;
		free(p);
		p = tmp_cell;
	}
}



Position list_header(List self) {
	return self;
}


Position list_first(List self) {
	return self->next;
}


Position list_advance(Position p) {
	return p->next;
}


ElementType list_retrive(Position p) {
	return p->element;
}


int main() {
	int i;
	List l = list_empty(NULL);
	Position p;

	p = l;
	for (i = 0; i < 10; i++) {
		list_insert(l, i, p);
		p = p->next;
	}
	
	p=l->next;
	while(p != NULL) {
		printf("%d\n", p->element);
		p = p->next;
	}

	printf("%s\n","hello world");
	return 0;
}
