/**
 * File Name:kmp_matcher.c
 * Description:
 * Create Date:17-02-2012
 * Last Modified:Fri Feb 17 01:34:40 2012
 *
 */

#include <stdio.h>
#include <string.h>

void compute_prefix_function(char *pattern, int pi[]) {
    int m = strlen(pattern);
    pi[0] = 0;
    int k = 0;
    int q = 0;
    for (q = 1; q < m; q++) {
        while(k > 0 && pattern[k] != pattern[q]) {
            k = pi[k];
        }
        if (pattern[k] == pattern[q]) {
            k += 1;
        }
        pi[q] = k;
    }
    
}

void kmp_matcher(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int pi[100] = {0};
    compute_prefix_function(pattern, pi);
    int q = 0;
    int i = 0;
    for (; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = pi[q];
        }
        if (pattern[q] == text[i]) {
            q = q + 1;
        }
        if (q == m) {
            printf("pattern occurs with shift %d\n", i - m + 1);
            q = pi[q];
        }
    }
}

int main() {
    const char *text = "abababaababacb";
    const char *pattern = "ababacb";
    //TODO  how to select d and q
    kmp_matcher(text, pattern);
    return 0;
}
