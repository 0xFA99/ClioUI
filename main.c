#include <ncurses.h>

#include "window.h"
#include "mystring.h"
#include "la.h"

int
main(void)
{
    int ch;

    String string1 = string("Window 1");
    String string2 = string("Window 2");
    String string3 = string("Window 3");
    String string4 = string("Window 4");

    WINDOW *LT = NULL;
    WINDOW *RT = NULL;
    WINDOW *LD = NULL;
    WINDOW *RD = NULL;

    initscr();
    cbreak();
    noecho();

    keypad(stdscr, true);

    while ((ch = getch()) != KEY_F(1)) {
        LT = createWindow(&string1, LEFT, vec2i(COLS / 2, 5), vec2i(0, 1));
        RT = createWindow(&string2, RIGHT, vec2i(COLS / 2, 5), vec2i(COLS / 2, 1));
        LD = createWindow(&string3, LEFT, vec2i(COLS / 2, 5), vec2i(0, 6));
        RD = createWindow(&string4, CENTER, vec2i(COLS / 2, 5), vec2i(COLS / 2, 6));
    }

    freeString(&string1);
    freeString(&string2);
    freeString(&string3);
    freeString(&string4);

    destroyWindow(LT);
    destroyWindow(RT);
    destroyWindow(LD);
    destroyWindow(RD);

    endwin();

    return 0;
}
