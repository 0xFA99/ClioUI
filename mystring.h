#ifndef MYSTRING_H
#define MYSTRING_H

#include <stddef.h>

typedef struct {
    char *value;
    size_t length;
} String;

String string(const char *str);

void freeString(String *str);

#endif
