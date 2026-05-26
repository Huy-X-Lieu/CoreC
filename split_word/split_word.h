//
// Created by Huy Lieu on 5/25/26.
//

#ifndef COREC_SPLIT_WORD_H
#define COREC_SPLIT_WORD_H
#include <stddef.h>

/*
 * Splits the mutable string s into space-separated words.
 *
 * The function stores pointers to the starts of words in the words array.
 * It does not allocate memory or copy word contents; each stored pointer points
 * into s, so those pointers remain valid only while s remains alive and
 * unchanged.
 *
 * The input string s may be modified. Space delimiters between extracted words
 * can be replaced with '\0' so each stored pointer can be used as a C string.
 *
 * Leading, trailing, and repeated spaces are ignored. Only the space character
 * ' ' is treated as a delimiter; tabs and other whitespace are not split.
 *
 * At most capacity word pointers are stored. The return value is the number of
 * words stored, not necessarily the total number of words in s when capacity is
 * smaller than the input word count.
 *
 * Returns 0 when s is NULL, words is NULL, capacity is 0, or no words are found.
 */
size_t split_words(char *s, char **words, size_t capacity);
void test_split_words(void);
#endif //COREC_SPLIT_WORD_H
