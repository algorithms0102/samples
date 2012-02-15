#ifndef _DLIST_H
#define _DLIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _DListRet{
	DLIST_RET_OK,
	DLIST_RET_OOM,
	DLIST_RET_STOP,
	DLIST_RET_PARAMS,
	DLIST_RET_FAIL
}DListRet;

struct _DList;
typedef struct _DList DList;

typedef DListRet (*DListDataPrintFunc)(void *data);

DList dlist_create(void);
DListRet dlist_insert(DList *thiz, size_t index, void *data);
DListRet dlist_prepend(DList *thiz, void *data);
DListRet dlist_append(DList *thiz, void *data);

DListRet dlist_print(DList *thiz, DListDataPrintFunc print);
#ifdef __cplusplus
}
#endif

#endif

