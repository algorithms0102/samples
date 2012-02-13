/**
 * File Name:strstr.c
 * Description:
 * Create Date:13-02-2012
 * Last Modified:Mon Feb 13 20:58:20 2012
 *
 */

#include <stdio.h>
#include <string.h>
/**
 * brute force version
 * it takes O(n * m) time
 */
int strstr_bf(const char *string, const char *substring) {
    //string and substring are not allowed to be empty
    if (string == NULL || substring == NULL) {
        return -1;
    }
    //get the length  of two strings
    int len_str = strlen(string);
    int len_substr = strlen(substring);
    //string should be equal or longer than substring
    if (len_str < len_substr) {
        return -1;
    }

    int len = len_str - len_substr;
    int i;
    int j;

    for (i = 0; i <= len; i++) {
        for (j = 0; j < len_substr; j++) {
            if(string[i+j] != substring[j]) {
                break;
            }
        }
        if (j == len_substr) {
            return i;
        }
    }
    return -1;
}


int main() {

    char *string = "abcdefghijklmn";
    char *substring = "def";
    int index = strstr_bf(string, substring);
    printf("%d\n", index);
    return 0;
}
