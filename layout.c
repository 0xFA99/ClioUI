#include "layout.h"

#include <ncurses.h>
#include <stdint.h>
#include <stddef.h>

static void
setHorizontal(Layout *layout, Item *item, uint8_t index)
{
    int itemWidth = layout->size.x / layout->itemCount;

    if (index == 0) {
        if ((item->itemType) == WINDOW_TYPE) {
            Window *currentWindow = (Window *)item->obj;
            currentWindow->pos.x = 0;
            currentWindow->size.x = itemWidth;

            updateWindow(currentWindow);

        } else if ((item->itemType) == LAYOUT_TYPE) {
            Layout *currentLayout = (Layout *)item->obj;
            currentLayout->pos.x = 0;
            currentLayout->size.x = itemWidth;

            updateLayout(currentLayout);
        }
    } else if (index == (layout->itemCount - 1)) {
        if ((item->itemType) == WINDOW_TYPE) {
            Window *currentWindow = (Window *)item->obj;
            currentWindow->pos.x = itemWidth * index + 1;
            currentWindow->size.x = itemWidth;

            updateWindow(currentWindow);

        } else if ((item->itemType) == LAYOUT_TYPE) {
            Layout *currentLayout = (Layout *)item->obj;
            currentLayout->pos.x = itemWidth * index + 1;
            currentLayout->size.x = itemWidth;
            updateLayout(currentLayout);
        }
    } else {
        if ((item->itemType) == WINDOW_TYPE) {
            Window *currentWindow = (Window *)item->obj;
            currentWindow->pos.x = itemWidth * index + 1;
            currentWindow->size.x = itemWidth * index;
            updateWindow(currentWindow);

        } else if ((item->itemType) == LAYOUT_TYPE) {
            Layout *currentLayout = (Layout *)item->obj;
            currentLayout->pos.x = itemWidth * index;
            currentLayout->size.x = itemWidth * index;

            updateLayout(currentLayout);
        }
    }
}

static void
setVertical(Layout *layout, Item *item, uint8_t index)
{
    int layoutHeight = layout->size.y;

    if ((item->itemType) == WINDOW_TYPE) {
        Window *currentWindow = (Window *)item->obj;
        currentWindow->pos.y = (layoutHeight * index) + 1;
        currentWindow->size.y = layoutHeight * (index + 1);

        updateWindow(currentWindow);

    } else {
        Layout *currentLayout = (Layout *)item->obj;
        currentLayout->pos.y = (layoutHeight * index) + 1;
        currentLayout->pos.y = layoutHeight * (index + 1);

        updateLayout(currentLayout);
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
        newLayout.pos.x = 0;
        newLayout.pos.y = 0;
    } else {
        Layout *parentLayout = (Layout *)parent;
        newLayout.size.x = parentLayout->size.x;
        newLayout.size.y = parentLayout->size.y;
        newLayout.pos.x = parentLayout->pos.x;
        newLayout.pos.y = parentLayout->pos.y;
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
    if ((layout->itemCount) > 0) {
        for (uint8_t i = 0; i < layout->itemCount; i++) {
            if ((layout->type) == HORIZONTAL) {
                setHorizontal(layout, &layout->items[i], i);
            } else {
                setVertical(layout, &layout->items[i], i);
            }
        }
    }
}

