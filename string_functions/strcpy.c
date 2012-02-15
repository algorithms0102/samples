/**
 * File Name:strcpy.c
 * Description:
 * Create Date:13-02-2012
 * Last Modified:Mon Feb 13 22:44:37 2012
 *
 */

#include <stdio.h>
#include <assert.h>
/**
 * copy string from src to dest
 */
char *strcpy(const char *str_src, char *str_dest) {
	//if src and dest are equal, return dest
	if(str_src == str_dest) {
		return str_dest;
	}
	//make sure src and dest are not null
	assert((str_src != NULL) && (str_dest != NULL));
	char *addr = str_dest;
	while ((*(str_dest++) = *(str_src++)) != '\0'); 
	return addr;
}


int main() {
	char src[] = "hello world!";
	char dest[] = "";
	strcpy(src, dest);
	printf("%s\n", dest);
	return 0;
}
