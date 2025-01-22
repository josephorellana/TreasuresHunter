#include "ui_adapter.h"

typedef enum {
    EASY = 0,
    MEDIUM,
    HARD,
    SELECTED,
    HELP,
    EXIT
} menu_option;

menu_option display_menu();

void print_menu(menu_option option);

menu_option get_menu_option(menu_option option);