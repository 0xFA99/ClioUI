#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

#include "la.h"
#include "mystring.h"

typedef enum { LEFT, CENTER, RIGHT } ALIGNMENT;

typedef struct {
    Vec2i size;
    Vec2i pos;
    WINDOW *window;
    String title;
} Window;

WINDOW *createWindow(String *title, ALIGNMENT align, Vec2i size, Vec2i pos);

void destroyWindow(WINDOW *win);

#endif
