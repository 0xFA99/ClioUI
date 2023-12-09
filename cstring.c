#include "cstring.h"

#include <string.h>

String
string(const char *text)
{
    String newString;
    newString.text = (char *)text;
    newString.length = strlen(text);

    return newString;
}

void
setText(String *str, const char *text)
{
    str->text = (char *)text;
    str->length = strlen(text);
}

