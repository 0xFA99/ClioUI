CC=cc
CFLAGS="-Wall -Wextra -pedantic -g -lncurses -ltinfo"
SOURCES="main.c cstring.c la.c window.c layout.c"

$CC $SOURCES -o main $CFLAGS
