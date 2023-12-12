#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <stdint.h>

#include "la.h"
#include "cstring.h"

typedef enum { LEFT, CENTER, RIGHT } ALIGNMENT;

typedef struct {
    uint16_t     colorPair;
    ALIGNMENT   align;
    Vec2i       size;
    Vec2i       pos;
    WINDOW*     window;
    String      title;
} Window;

Window createWindow(Vec2i size, Vec2i pos);
Window createWindowTitle(Vec2i size, Vec2i pos, const char *title, ALIGNMENT align);

void setWindowTitle(Window *win, const char *title, ALIGNMENT align);
void setWindowBorderColor(Window *win, short colorPair);

void updateWindow(Window *win);

#endif
