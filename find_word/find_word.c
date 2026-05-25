#include "find_word.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
//
// Created by Huy Lieu on 5/25/26.
//
char *find_word(char *s, const char *word) {
    if (s == NULL || word == NULL)
        return NULL;

    if (*word == '\0')
        return s;

    char *current = s;
    char *p_word = NULL;
    char *check = NULL;

    while (*current != '\0') {
        if (*current == *word) {
            check = current + 1;
            p_word = word + 1;

            while (*check != '\0') {
                if (*p_word == '\0')
                    return current;

                if (*check != *p_word) {
                    break;
                }

                check++;
                p_word++;
            }
            if (*p_word == '\0')
                return current;
        }
        current ++;
    }

    return NULL;
}

void test_find_word(void) {
    char a[] = "banana";
    char a_word[] = "ana";
    char *a_result = find_word(a, a_word);
    assert(a_result == a + 1);
    assert(strcmp(a_result, "anana") == 0);

    char b[] = "banana";
    char b_word[] = "nana";
    char *b_result = find_word(b, b_word);
    assert(b_result == b + 2);
    assert(strcmp(b_result, "nana") == 0);

    char c[] = "banana";
    char c_word[] = "apple";
    char *c_result = find_word(c, c_word);
    assert(c_result == NULL);

    char d[] = "hello";
    char d_word[] = "hello";
    char *d_result = find_word(d, d_word);
    assert(d_result == d);
    assert(strcmp(d_result, "hello") == 0);

    char e[] = "hello";
    char e_word[] = "";
    char *e_result = find_word(e, e_word);
    assert(e_result == e);
    assert(strcmp(e_result, "hello") == 0);

    char f[] = "";
    char f_word[] = "a";
    char *f_result = find_word(f, f_word);
    assert(f_result == NULL);

    char g[] = "";
    char g_word[] = "";
    char *g_result = find_word(g, g_word);
    assert(g_result == g);
    assert(strcmp(g_result, "") == 0);

    char h[] = "aaaaa";
    char h_word[] = "aa";
    char *h_result = find_word(h, h_word);
    assert(h_result == h);
    assert(strcmp(h_result, "aaaaa") == 0);

    printf("Passed all find_word test cases.\n");
}
