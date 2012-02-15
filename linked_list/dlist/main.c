/**
 * File Name:main.c
 * Description:
 * Create Date:05-11-2011
 * Last Modified:Sat Nov  5 14:01:40 2011
 * Author:7655cjc@gmail.com
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
