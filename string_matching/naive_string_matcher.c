//
//  main.c
//  naive_string_matcher_v1
//
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int naive_string_matcher(char *text, char *pattern);
/**
 * find the first match of pattern in text
 * return shift on finding, or return -1
 * TODO find the next on repeated calling of this function
 */
int naive_string_matcher(char *text, char *pattern) {
	int n = strlen(text); //length of text
	int m = strlen(pattern); //length of pattern
	int s = 0; //shift
	int max_s = n - m; //the maximum shift
	if (max_s < 0) { //if text is shorter than pattern
		return -1;	
	}
    for (; s <= max_s; s++) {
        if (strncmp(text+s, pattern, m) == 0) {
            return s;
        }
    }
    return -1;
}

int main (int argc, const char * argv[])
{

    char *text = "ABCDEFGHLMNOPQRS";
    char *pattern = "PQRS";
    if (naive_string_matcher(text, pattern) > -1) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}

