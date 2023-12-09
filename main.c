#include <ncurses.h>

#include "window.h"
#include "la.h"

int
main(void)
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    if (!has_colors()) {
        fprintf(stderr, "ERROR: Terminal doesn't support colors\n");
    }

    start_color();
    use_default_colors();

    init_pair(0, COLOR_WHITE, -1);
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_BLUE, -1);
    init_pair(4, COLOR_YELLOW, -1);

    Window win1 = createWindow(vec2i(50, 10), vec2i(1, 1));
    setWindowBorderColor(&win1, 1);
    wgetch(win1.window);

    setWindowTitle(&win1, "Hello World", LEFT);
    setWindowBorderColor(&win1, 2);
    wgetch(win1.window);

    setWindowTitle(&win1, "Hello World", CENTER);
    setWindowBorderColor(&win1, 3);
    wgetch(win1.window);

    setWindowTitle(&win1, "Hello World", RIGHT);
    setWindowBorderColor(&win1, 4);
    wgetch(win1.window);

    Window win2 = createWindowTitle(vec2i(50, 10), vec2i(1, 11), "WINDOW 2", CENTER);
    wgetch(win2.window);

    setWindowBorderColor(&win2, 1);
    wgetch(win2.window);

    endwin();
    return 0;
}
