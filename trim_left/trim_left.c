#include "trim_left.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
//
// Created by Huy Lieu on 5/25/26.
//
char *trim_left(char *s) {
    if (s == NULL)
        return NULL;

    char *current = s;
    while (*current == ' ')
        current++;

    return current;
}

void test_trim_left(void) {
    char a[] = "   hello";
    char *a_result = trim_left(a);
    assert(a_result == a + 3);
    assert(strcmp(a_result, "hello") == 0);

    char b[] = "hello";
    char *b_result = trim_left(b);
    assert(b_result == b);
    assert(strcmp(b_result, "hello") == 0);

    char c[] = "      ";
    char *c_result = trim_left(c);
    assert(c_result == c + 6);
    assert(strcmp(c_result, "") == 0);

    char d[] = "";
    char *d_result = trim_left(d);
    assert(d_result == d);
    assert(strcmp(d_result, "") == 0);

    char e[] = "  a b c";
    char *e_result = trim_left(e);
    assert(e_result == e + 2);
    assert(strcmp(e_result, "a b c") == 0);

    printf("Passed all trim_left test cases.\n");
}
