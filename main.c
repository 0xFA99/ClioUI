#include <ncurses.h>

#include "layout.h"
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

    Layout hLayout = layout(NULL, HORIZONTAL);

    Window win1 = createWindowTitle(
            vec2i(20, 10), vec2i(1, 1), "WINDOW 1", CENTER);

    Window win2 = createWindowTitle(
            vec2i(20, 10), vec2i(21, 1), "WINDOW 2", CENTER);

    Window win3 = createWindowTitle(
            vec2i(20, 10), vec2i(21, 1), "WINDOW 3", CENTER);

    addWindowToLayout(&hLayout, &win1);
    addWindowToLayout(&hLayout, &win2);
    addWindowToLayout(&hLayout, &win3);

    updateLayout(&hLayout);

    wgetch(win3.window);

    endwin();
    return 0;
}
