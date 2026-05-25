#include "RemoveACharFromString.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void remove_char(char *s, char target) {
    if (s == NULL || *s == '\0')
        return;

    if (target == '\0')
        return;

    char *p_str = s;
    int skipChars = 1;
    while (*p_str != '\0') {
        if (*p_str == target) {
            while (*(p_str + skipChars) == target)
                skipChars++;
            if (*(p_str +skipChars) == '\0') {
                *p_str = '\0';
                return;
            }
            *p_str = *(p_str + skipChars);
            *(p_str + skipChars) = target;
        }
        p_str ++;
    }
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
