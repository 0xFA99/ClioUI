CC=cc
CFLAGS="-Wall -Wextra -pedantic -g -lncurses -ltinfo"
SOURCES="main.c mystring.c la.c window.c"

$CC $SOURCES -o main $CFLAGS
