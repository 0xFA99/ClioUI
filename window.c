#include "window.h"

Window
createWindow(Vec2i size, Vec2i pos)
{
    Window newWindow;
    newWindow.colorPair = 0;
    newWindow.align = LEFT;
    newWindow.size = size;
    newWindow.pos = pos;
    newWindow.window = newwin(size.y, size.x, pos.y, pos.x);
    newWindow.title = (String){"", 0};

    updateWindow(&newWindow);

    return newWindow;
}

Window
createWindowTitle(Vec2i size, Vec2i pos, const char *title, ALIGNMENT align)
{
    Window newWindow;
    newWindow.colorPair = 0;
    newWindow.align = align;
    newWindow.size = size;
    newWindow.pos = pos;
    newWindow.window = newwin(size.y, size.x, pos.y, pos.x);
    newWindow.title = string(title);

    updateWindow(&newWindow);

    return newWindow;
}

void
setWindowTitle(Window *win, const char *title, ALIGNMENT align)
{
    win->title = string(title);
    win->align = align;

    updateWindow(win);
}

void
setWindowBorderColor(Window *win, short colorPair)
{
    win->colorPair = colorPair;

    updateWindow(win);
}

void
updateWindow(Window *win)
{
    wborder(win->window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(win->window);

    wresize(win->window, win->size.y, win->size.x);
    mvwin(win->window, win->pos.y, win->pos.x);

    // Border
    wattron(win->window, COLOR_PAIR(win->colorPair));
    box(win->window, 0, 0);
    wattroff(win->window, COLOR_PAIR(win->colorPair));

    // Title
    if (win->title.length != 0) {
        int titleX = 0;
        if (win->align == LEFT) {
            titleX = win->pos.x + 2;
        } else if (win->align == CENTER) {
            titleX = (win->size.x - (win->title.length + 2)) / 2;
        } else {
            titleX = (win->size.x - (win->title.length + 2)) - 3;
        }

        mvwprintw(win->window, 0, titleX, " %s ", win->title.text);
    }

    wrefresh(win->window);
}

