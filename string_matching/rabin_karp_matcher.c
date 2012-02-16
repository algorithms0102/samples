/**
 * File Name:rabin_karp_matcher.c
 * Description:
 * Create Date:16-02-2012
 * Last Modified:Thu Feb 16 22:20:10 2012
 *
 */

#include <stdio.h>
#include <string.h>


void rabin_karp_matcher(const char *text, const char *pattern, int d, int q);
void rabin_karp_matcher(const char *text, const char *pattern, int d, int q) {
    int n = strlen(text);
    int m = strlen(pattern);
    int h = 1;
    int i = 0;
    for (;i < m - 1; i++) {
        h *= d;
        if (h > q) {
            h %= q;
        }
    }
    
    int p = 0;
    int t = 0;
    for (i = 0; i < m; i++) {
        p = (d * p + (pattern[i] - '0')) % q;
        t = (d * t + (text[i] - '0')) % q;
    }
    
    
    int max_shift = n - m;
    for (i = 0; i <= max_shift; i++) {
        if (p == t) {
            if (strncmp(text+i, pattern, m) == 0) {
                printf("valid match position: %d\n", i);
            } else {
                printf("spurious hit: %d\n", i);
            }
        }       
        if (i < max_shift) {
            t = (d * (t - h * (text[i] - '0')) + text[i + m] - '0') % q;
            if (t < 0) {
                t += q;
            }
        }
        
    }
    
}


int main() {
    const char *text = "2359023141526739921";
    const char *pattern = "31415";
    //TODO  how to select d and q
    rabin_karp_matcher(text, pattern, 10, 13);
    return 0;
}
