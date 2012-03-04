/**
 * File Name:strcpy_.c
 * Description:
 * Create Date:13-02-2012
 * Last Modified:Sat Mar  3 21:09:18 2012
 *
 */

#include <stdio.h>
#include <assert.h>
/**
 * copy string from src to dest
 */
char *strcpy_(const char *str_src, char *str_dest) {
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
	printf("%s\n", src);
	strcpy_(src, dest);
	printf("%s\n", dest);
	printf("%s\n", src);
	return 0;
}
