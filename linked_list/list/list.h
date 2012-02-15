typedef int ElementType;

#ifndef _List_H
#define _List_H

struct _ListNode;
typedef struct _ListNode *_PtrToListNode;
typedef _PtrToListNode List;
typedef _PtrToListNode Position;

List list_empty(List self);
int list_is_empty(List self);
int list_is_last(List self, Position p);
Position list_find(List self, ElementType x);
void list_delete_element(List self, ElementType x);
Position list_find_previous(List self, ElementType x);
void list_insert(List self, ElementType x, Position p);
void list_delete(List self);
Position list_header(List self);
Position list_first(List self);
Position list_advance(Position p);
ElementType list_retrive(Position p);
#endif
