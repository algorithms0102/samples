/**
 * File Name:main.c
 * Description:
 * Create Date:05-11-2011
 * Last Modified:Wed Feb 15 22:19:37 2012
 *
 */

#include <stdio.h>
#include <assert.h>
#include "dlist.h"

static DListRet print_int(void *data) {
	printf("%d ", (int)data);
	return DLIST_RET_OK;
}

int main(int argc, char *argv[]) {
	return 0;
}
