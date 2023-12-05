#include "window.h"

WINDOW *
createWindow(String *title, ALIGNMENT align, Vec2i size, Vec2i pos)
{
    WINDOW *newWindow = newwin(size.y, size.x, pos.y, pos.x);
    box(newWindow, 0, 0);

    if (align == LEFT) {
        mvwprintw(newWindow, 0, pos.x + 2, "%s", title->value);
    } else if (align == CENTER) {
        mvwprintw(newWindow, 0, (pos.x - title->length) / 2, "%s", title->value);
    } else {
        mvwprintw(newWindow, 0, (size.x - title->length) - 2, "%s", title->value);
    }

    wrefresh(newWindow);
    refresh();

    return newWindow;
}

void
destroyWindow(WINDOW *win)
{
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(win);

    delwin(win);
}

