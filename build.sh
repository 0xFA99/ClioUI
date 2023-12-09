CC=cc
CFLAGS="-Wall -Wextra -pedantic -g -lncurses -ltinfo"
SOURCES="main.c cstring.c la.c window.c"

$CC $SOURCES -o main $CFLAGS
