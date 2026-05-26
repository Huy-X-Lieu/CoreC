//
// Created by Huy Lieu on 5/25/26.
//

#ifndef COREC_SPLIT_WORD_H
#define COREC_SPLIT_WORD_H
#include <stddef.h>

size_t split_words(char *s, char **words, size_t capacity);
void test_split_words(void);
#endif //COREC_SPLIT_WORD_H
