/*
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
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

#include "la.h"
#include "cstring.h"

typedef enum { LEFT, CENTER, RIGHT } ALIGNMENT;

typedef struct {
    short colorPair;
    ALIGNMENT align;    // 4
    Vec2i   size;       // 8
    Vec2i   pos;        // 8
    WINDOW  *window;    // 8
    String  title;      // 16
} Window;

Window createWindow(Vec2i size, Vec2i pos);
Window createWindowTitle(Vec2i size, Vec2i pos, const char *title, ALIGNMENT align);

void setWindowTitle(Window *win, const char *title, ALIGNMENT align);
void setWindowBorderColor(Window *win, short colorPair);

void updateWindow(Window *win);

#endif
