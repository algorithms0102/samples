/**
 * File Name:string.c
 * Description:
 * Create Date:13-02-2012
 * Last Modified:Mon Feb 13 23:22:04 2012
 *
 */

#include <stdio.h>
/**
 * concat two strings
 *
 */
char *strcat(char * dst, const char * src) {
	char * cp = dst;
	while ( *cp ) {
		cp++;
	}
	while ( *cp++ = *src++ ); 

	return dst;
}
/**
 * compare two strings, if src > dst return 1
 * if src < dst return -1, if src == dst, return 0
 */
int strcmp(const char * src, const char * dst) {
	int ret = 0;
	
	while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst) {
		src++;
		dst++;
	}

	if (ret < 0) {
		return -1;
	} else if (ret > 0) {
		return 1;
	}
	
	return ret;
}

int strlen(const char * str) {
	const char *eos = str; //declare a pointer to a const char
	while (*eos++);
	return (int)(eos - str - 1);
}

int main() {
	char a[] = "abc";
	char b[] = "def";
	printf("cat 'abc' and 'def': %s\n", strcat(a, b));
	printf("compare 'abc' and 'def': %d\n", strcmp(a, b));
	printf("the length of 'def' is': %d\n", strlen(b));
	return 0;
}
