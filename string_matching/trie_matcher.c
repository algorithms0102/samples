/**
 * File Name:trie_matcher.c
 * Description:
 * Create Date:17-02-2012
 * Last Modified:Sat Feb 18 08:17:23 2012
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXN 100010
#define MAXM 11
#define KIND 26

struct trie_node {
    int count;
    struct trie_node * next[KIND];
} a[MAXN * MAXM], *trie_root;

int m = 0;

void insert(struct trie_node * root, char *str);
int delete(struct trie_node * root, char *str);
int count(struct trie_node * root, char *str);

void insert(struct trie_node * root, char *str) {
    struct trie_node * p = root;
    int i = 0;
    for (; str[i]; i++) {
        int x = str[i] - 'a';
        if (p->next[x] == NULL) {
            //init a node
            a[m].count = 0;
            memset(a[m].next, 0, sizeof(a[m].next));
            p->next[x] = &a[m++];
            
        }
        p = p->next[x];
    }
    p->count++;
}

int delete(struct trie_node * root, char *str) {
    struct trie_node * p = root;
    int i = 0;
    for (; str[i]; i++) {
        int x = str[i] - 'a';
        if (p->next[x] == NULL) {
            return 0;
        }
        p = p->next[x];
    }
    if (p->count > 0) {
        p->count--;
    } else {
        return 0;
    }
    return 1;
}


int count(struct trie_node * root, char *str) {
    struct trie_node * p = root;
    int i = 0;
    for (; str[i]; i++) {
        int x = str[i] - 'a';
        if (p->next[x] == NULL) {
            return 0;
        }
        p = p->next[x];
    }
    return p->count;
}


int main() {
    m = 0;
    a[m].count = 0;
    memset(a[m].next, 0, sizeof(a[m].next));
    trie_root = &a[m++];
    char str[MAXM];
    
    while (gets(str), strcmp(str, "")) {
        insert(trie_root, str);
    }
    
    while (gets(str)) {
        printf("%d\n", count(trie_root,str));
    }
}
