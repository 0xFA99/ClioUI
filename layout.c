#include "layout.h"

#include <ncurses.h>
#include <stdint.h>
#include <stddef.h>

static void
setHorizontal(Layout *layout, Item *item, uint8_t index)
{
    int layoutWidth = layout->size.x;
    int totalItem   = layout->itemCount;
    int normalize = (layoutWidth / totalItem) / layoutWidth;

    if ((item->itemType) == WINDOW_TYPE) {
        Window *currentItem = (Window *)item->obj;
        currentItem->size.x  = layoutWidth * normalize;
        currentItem->pos.x   = layoutWidth * normalize * index + 1;
    } else {
        Layout *currentItem = (Layout *)item->obj;
        currentItem->size.x  = layoutWidth * normalize;
        currentItem->pos.x   = layoutWidth * normalize * index + 1;
    }

}

static void
setVertical(Layout *layout, Item *item, uint8_t index)
{
    int layoutHeight = layout->size.y;
    int totalItem = layout->itemCount;
    int normalize = (layoutHeight / totalItem) / layoutHeight;

    if ((item->itemType) == WINDOW_TYPE) {
        Window *currentItem = (Window *)item->obj;
        currentItem->size.y  = layoutHeight * normalize;
        currentItem->pos.y   = layoutHeight * normalize * index;
    } else {
        Layout *currentItem = (Layout *)item->obj;
        currentItem->size.y  = layoutHeight * normalize;
        currentItem->pos.y   = layoutHeight * normalize * index;
    }

}

Layout
layout(void *parent, LayoutType type)
{
    Layout newLayout;
    if (parent == NULL) {
        int x, y;
        getmaxyx(stdscr, y, x);
        newLayout.size.x = x;
        newLayout.size.y = y;
    } else {
        Layout *parentLayout = (Layout *)parent;
        newLayout.size.x = parentLayout->size.x;
        newLayout.size.y = parentLayout->size.y;
    }

    newLayout.itemCount = 0;
    newLayout.type = type;

    for (uint8_t i = 0; i < ITEMS_CAP; ++i) {
        newLayout.items[i].itemType = WINDOW_TYPE;
        newLayout.items[i].obj = NULL;
    }

    return newLayout;
}

void
addWindowToLayout(Layout *layout, Window *win)
{
    Item newItem;
    newItem.itemType = WINDOW_TYPE;
    newItem.obj = win;

    layout->items[layout->itemCount] = newItem;
    layout->itemCount += 1;

    if (layout->type == HORIZONTAL) {
        setHorizontal(layout, &newItem, layout->itemCount);
    } else {
        setVertical(layout, &newItem, layout->itemCount); 
    }

    updateLayout(layout);
}

void
addLayoutToLayout(Layout *parent, Layout *layout)
{
    Item newItem;
    newItem.itemType = LAYOUT_TYPE;
    newItem.obj = layout;

    parent->items[layout->itemCount] = newItem;
    parent->itemCount += 1;

    if (layout->type == HORIZONTAL) {
        setHorizontal(parent, &newItem, layout->itemCount);
    } else {
        setVertical(parent, &newItem, layout->itemCount);
    }

    updateLayout(layout);
}

void
updateLayout(Layout *layout)
{
    if (layout->itemCount > 0) {
        for (uint8_t i = 0; i < layout->itemCount - 1; ++i) {
            if ((layout->type) == HORIZONTAL) {
                setHorizontal(layout, &layout->items[i], i);
            } else {
                setVertical(layout, &layout->items[i], i);
            }
        }
    }

    return;
}

