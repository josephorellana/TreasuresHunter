#include "ui_adapter.h"
#include "curses.h"


KeyActionSettings key_action_settings = {
    .go_up    = KEY_UP,
    .go_down  = KEY_DOWN,
    .go_left  = KEY_LEFT,
    .go_right = KEY_RIGHT,
    .go_enter = 10,
    .go_help  = KEY_F(1),
    .go_quit  = 'q'
};


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

key_action get_key_action(int key) {
    if (key == key_action_settings.go_up) {
        return GO_UP;
    } else if (key == key_action_settings.go_down) {
        return GO_DOWN;
    } else if (key == key_action_settings.go_left) {
        return GO_LEFT;
    } else if (key == key_action_settings.go_right) {
        return GO_RIGHT;
    } else if (key == key_action_settings.go_enter) {
        return GO_ENTER;
    } else if (key == key_action_settings.go_help) {
        return GO_HELP;
    } else if (key == key_action_settings.go_quit) {
        return GO_QUIT;
    } else {
        return NO_ACTION;
    }
}

void set_key_action(int key, key_action action) {
    if (action == GO_UP) {
        key_action_settings.go_up = key;
    } else if (action == GO_DOWN) {
        key_action_settings.go_down = key;
    } else if (action == GO_LEFT) {
        key_action_settings.go_left = key;
    } else if (action == GO_RIGHT) {
        key_action_settings.go_right = key;
    } else if (action == GO_ENTER) {
        key_action_settings.go_enter = key;
    } else if (action == GO_HELP) {
        key_action_settings.go_help = key;
    } else if (action == GO_QUIT) {
        key_action_settings.go_quit = key;
    }
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