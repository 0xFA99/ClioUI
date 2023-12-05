#include "mystring.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_CAP 4095

String
string(const char *str)
{
    String newString;

    size_t stringLength = strlen(str);
    if (stringLength > STRING_CAP) {
        fprintf(stderr, "MAX String is: 4095 Characters!\n");
        newString.value = NULL;
        newString.length = 0;
        return newString;
    }

    newString.length = stringLength;
    newString.value = (char *)malloc(newString.length + 1);

    if (newString.value != NULL) {
        strncpy(newString.value, str, newString.length);
        newString.value[newString.length] = '\0';
    } else {
        fprintf(stderr, "ERROR: Failed to allocation memory.\n");
        exit(1);
    }

    return newString;
}

void
freeString(String *str)
{
    free(str->value);
    str->value = NULL;
    str->length = 0;
}

