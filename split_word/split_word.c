//
// Created by Huy Lieu on 5/25/26.
//
#include "split_word.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t split_words(char *s, char **words, size_t capacity) {
    if (s == NULL || words == NULL || capacity == 0)
        return 0;

    char *current = s;
    int count = 0;
    while (*current == ' ') {
        current++;
    }
    if (*current == '\0')
        return 0;

    while (*current != '\0' && capacity > count) {
        // get the first letter of the word
        while (*current == ' ')
            current++;
        *words = current;

        // get the last letter of the word and replace the space at the end
        // with '\0'
        while (*current != '\0' && *current != ' ') {
            current++;
        }
        *current = '\0';

        current++;
        words++;
        count++;
    }

    return count;
}

void test_split_words(void) {
    char a[] = "hello world";
    char *a_words[2];
    size_t a_count = split_words(a, a_words, 2);
    assert(a_count == 2);
    assert(strcmp(a_words[0], "hello") == 0);
    assert(strcmp(a_words[1], "world") == 0);

    char b[] = "   hello   world   ";
    char *b_words[2];
    size_t b_count = split_words(b, b_words, 2);
    assert(b_count == 2);
    assert(strcmp(b_words[0], "hello") == 0);
    assert(strcmp(b_words[1], "world") == 0);

    char c[] = "";
    char *c_words[1];
    size_t c_count = split_words(c, c_words, 1);
    assert(c_count == 0);

    char d[] = "      ";
    char *d_words[1];
    size_t d_count = split_words(d, d_words, 1);
    assert(d_count == 0);

    char e[] = "one";
    char *e_words[1];
    size_t e_count = split_words(e, e_words, 1);
    assert(e_count == 1);
    assert(strcmp(e_words[0], "one") == 0);

    char f[] = "a b c d";
    char *f_words[2];
    size_t f_count = split_words(f, f_words, 2);
    assert(f_count == 2);
    assert(strcmp(f_words[0], "a") == 0);
    assert(strcmp(f_words[1], "b") == 0);

    printf("Passed all split_words test cases.\n");
}
