#ifndef LAYOUT_H
#define LAYOUT_H

#include "window.h"
#include "la.h"

#include <stdint.h>

typedef enum { HORIZONTAL, VERTICAL, GRID } LayoutType;
typedef enum { WINDOW_TYPE, LAYOUT_TYPE } ItemType;

typedef struct {
    ItemType itemType;
    void *obj;
} Item;

#define ITEMS_CAP 64
typedef struct Layout {
    Vec2i size;
    Vec2i pos;
    Item items[ITEMS_CAP];
    uint8_t itemCount;
    LayoutType type;
} Layout;

Layout layout(void *parent, LayoutType type);

void addWindowToLayout(Layout *layout, Window *win);
void addLayoutToLayout(Layout *parent, Layout *layout);

void updateLayout(Layout *layout);

#endif
