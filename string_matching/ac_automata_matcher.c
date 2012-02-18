/**
 * File Name:ac_automata_matcher.c
 * Description:
 * Create Date:17-02-2012
 * Last Modified:Fri Feb 17 01:34:40 2012
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXN 10001
#define MAXM 51
#define KIND 26

struct node {
    int prefix;
    struct node *fail;
    struct node *next[26];
    
}*que[MAXN * MAXM], trie[MAXN * MAXM],  *root;

int cnt = 0;
char keyword[MAXM];
char str[MAXN * 2];

void insert(struct node *root, char *str);
void build(struct node *root);
int query(struct node *root, char *str);

void insert(struct node *root, char *str) {
    struct node *ptr = root;
    for (int i = 0; str[i]; i++) {
        int x = str[i] - 'a';
        if (ptr->next[x] == NULL) {
            trie[cnt].prefix = 0;
            trie[cnt].fail = NULL;
            memset(trie[cnt].next, 0, sizeof(trie[cnt].next));
            ptr->next[x] = &trie[cnt++];
        }
        ptr = ptr->next[x];
    }
    ptr->prefix++;
}//insert

void build(struct node *root) {
    int head = 0, tail = 0;
    root->fail = NULL;
    que[head++] = root;
    while (head != tail) {
        struct node *tmp = que[tail++];
        struct node *ptr = NULL;
        for (int i = 0; i < KIND; i++) {
            if (tmp->next[i] != NULL) {
                if (tmp == root) {
                    tmp->next[i]->fail = root;
                } else {
                    ptr = tmp->fail;
                    while (ptr != NULL) {
                        if (ptr->next[i] != NULL) {
                            tmp->next[i]->fail = ptr->next[i];
                            break;
                        }
                        ptr = ptr->fail;
                    }
                    if (ptr == NULL) {
                        tmp->next[i]->fail = root;
                    }
                }//if_else
                que[head++] = tmp->next[i];
            }//if
        }//for(i)
    }//while (head != tail)
}//Build

int query(struct node *root, char *str) {
    int ret = 0;
    struct node *ptr = root;
    for (int i = 0; str[i]; i++) {
        int x = str[i] - 'a';
        while (ptr->next[x] == NULL && ptr != root) {
            ptr = ptr->fail;
        }
        ptr = ptr->next[x];
        if (ptr == NULL) {
            ptr = root;
        }
        struct node *tmp = ptr;
        while (tmp != root && tmp->prefix != -1) {
            ret += tmp->prefix;
            tmp->prefix = -1;
            tmp = tmp->fail;
        }
    }//for(i)
    return ret;
}
/*
 Sample Input
 
 1
 5
 she
 he
 say
 shr
 her
 yasherhs
 
 
 
 Sample Output
 
 3
 
*/
int main() {
    int cas, n;
    scanf("%d", &cas);
    while (cas--) {
        // head = tail = 0;
        cnt = 0;
        trie[cnt].prefix = 0;
        trie[cnt].fail = NULL;
        memset(trie[cnt].next, 0, sizeof(trie[cnt].next));

        root = &trie[cnt++];
        
        scanf("%d%*c", &n);
        while (n--) {
            gets(keyword);
            insert(root, keyword);
        }
        build(root);//构造自动机
        scanf("%s", str);
        printf("%d\n", query(root, str));
    }
    return 0;
}