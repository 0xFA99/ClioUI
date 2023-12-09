#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

#include <stddef.h>

typedef struct {
    char *text;
    size_t length;
} String;

String string(const char *text);
void setText(String *str, const char *text);

#endif

