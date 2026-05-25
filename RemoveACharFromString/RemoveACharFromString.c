#include "RemoveACharFromString.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void swap_chars(char *char_1, char *char_2) {
    char temp = *char_1;
    *char_1 = *char_2;
    *char_2 = temp;
}

void remove_char(char *s, char target) {
    if (s == NULL || *s == '\0')
        return;

    if (target == '\0')
        return;

    char *p_str = s;
    char *p_non_target = NULL;
    while (*p_str != '\0') {
        if (*p_str == target) {
            p_non_target = p_str + 1;
            while (*p_non_target == target) {
                p_non_target++;
            }
            swap_chars(p_str, p_non_target);
        }

        if (*p_str == '\0')
            return;

        p_str++;
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
