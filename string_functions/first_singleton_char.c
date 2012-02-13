/**
 * File Name:first_singleton_char.c
 * Description: find the first non repeat char in a string
 * Create Date:13-02-2012
 * Last Modified:Mon Feb 13 22:10:00 2012
 *
 */

#include <stdio.h>

/**
 * find the first char which only appears once in the string
 * hash version
 */
char first_singleton_char_hash(char *str) {
	if (!str) {
		return '\0';
	}
	const int table_size = 256;
	int hash_table[table_size] = {0};//set all value to be zero

	char *key = str;
	while (*(key) != '\0') {
		hash_table[*(key++)]++;
	}
	while (*str != '\0') {
		if (hash_table[*str] == 1) {
			return *str;
		}
		str++;
	}
	return '\0';
}


int main() {
	char *str = "aabbccddeeffdhhrasdfqwer";
	printf("%c\n", first_singleton_char_hash(str));
	return 0;
}
