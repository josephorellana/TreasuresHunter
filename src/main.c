#include "ui_adapter.h"
#include "menu.h"

int main() {
    UIAdapterInterface *ui_adapter = get_ui_adapter();
    ui_adapter->init_screen();

    menu_option option = EASY;

    while (1)
    {
        option = display_menu();
    } while (option != EXIT);

    ui_adapter->end_screen();
    return 0;
}