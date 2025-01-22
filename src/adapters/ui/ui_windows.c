#include "ui_adapter.h"
#include "curses.h"

void init_screen() {
    WINDOW* window = initscr();
    keypad(window, true);
    noecho();
    cbreak();
}


void print_text(int y, int x, const char *text) {
    mvprintw(y, x, "%s", text);
    refresh();
}


int get_char() {
    return getch();
}


void clean_screen() {
    clear();
}


void end_screen(void) {
    endwin();
}



UIAdapterInterface ui_windows = {
    .clean_screen = clean_screen,
    .end_screen   = end_screen,
    .get_char     = get_char,
    .init_screen  = init_screen,
    .print_text   = print_text
};