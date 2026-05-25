#include "RemoveACharFromString.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void remove_char(char *s, char target) {
    if (s == NULL)
        return;

    char *read = s;
    char *write = s;

    while (*read != '\0') {
        if (*read != target) {
            *write = *read;
            write++;
        }
        read++;
    }
    *write = '\0';
}

void test_remove_char(void) {
    char a[] = "banana";
    remove_char(a, 'a');
    assert(strcmp(a, "bnn") == 0);

    char b[] = "aaaa";
    remove_char(b, 'a');
    assert(strcmp(b, "") == 0);

    char c[] = "hello";
    remove_char(c, 'z');
    assert(strcmp(c, "hello") == 0);

    char d[] = "";
    remove_char(d, 'x');
    assert(strcmp(d, "") == 0);

    char e[] = "abcabc";
    remove_char(e, 'b');
    assert(strcmp(e, "acac") == 0);

    char f[] = "mississippi";
    remove_char(f, 's');
    assert(strcmp(f, "miiippi") == 0);

    printf("Passed all test cases.");
}
