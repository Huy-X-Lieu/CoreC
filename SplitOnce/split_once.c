#include "split_once.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
//
// Created by Huy Lieu on 5/24/26.
//
char *split_once(char *s, char delimiter) {
    if (s == NULL)
        return NULL;

    char *current = s;
    while (*current != '\0') {
        if (*current == delimiter) {
            *current = '\0';
            return current + 1;
        }
        current++;
    }

    return NULL;
}

void test_split_once(void) {
    char a[] = "name:age";
    char *a_right = split_once(a, ':');
    assert(a_right != NULL);
    assert(strcmp(a, "name") == 0);
    assert(strcmp(a_right, "age") == 0);

    char b[] = ":start";
    char *b_right = split_once(b, ':');
    assert(b_right != NULL);
    assert(strcmp(b, "") == 0);
    assert(strcmp(b_right, "start") == 0);

    char c[] = "end:";
    char *c_right = split_once(c, ':');
    assert(c_right != NULL);
    assert(strcmp(c, "end") == 0);
    assert(strcmp(c_right, "") == 0);

    char d[] = "no_delimiter";
    char *d_right = split_once(d, ':');
    assert(d_right == NULL);
    assert(strcmp(d, "no_delimiter") == 0);

    char e[] = "";
    char *e_right = split_once(e, ':');
    assert(e_right == NULL);
    assert(strcmp(e, "") == 0);

    char f[] = "a:b:c";
    char *f_right = split_once(f, ':');
    assert(f_right != NULL);
    assert(strcmp(f, "a") == 0);
    assert(strcmp(f_right, "b:c") == 0);

    printf("Passed all split_once test cases.\n");
}
