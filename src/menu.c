#include "menu.h"

menu_option display_menu() {
    menu_option option = EASY, new_option;

    do {
        print_menu(option);
        new_option = get_menu_option(option);

        if ( new_option != SELECTED ) {
            option = new_option;
        }
    } while ( new_option == EASY || new_option == MEDIUM || new_option == HARD );

    return option;    
}

void print_menu(menu_option option) {
    UIAdapterInterface *ui_adapter = get_ui_adapter();
    ui_adapter->clean_screen();
    
    ui_adapter->clean_screen();
    ui_adapter->print_text(1, 1, "*******************************");
    ui_adapter->print_text(2, 1, "*                             *");
    ui_adapter->print_text(3, 1, "*      CAZADOR DE TESOROS     *");
    ui_adapter->print_text(4, 1, "*                             *");
    ui_adapter->print_text(5, 1, "*******************************");
    ui_adapter->print_text(8, 5, "  Fácil");
    ui_adapter->print_text(9, 5, "  Medio");
    ui_adapter->print_text(10, 5, "  Difícil");

    int row = 8 + option;
    ui_adapter->print_text(row, 5, ">");
}


menu_option get_menu_option(menu_option option) {
    UIAdapterInterface *ui_adapter = get_ui_adapter();
    int _char = 0;
    key_action action = GO_DOWN;

    do {
        _char = ui_adapter->get_char();
        action = ui_adapter->get_key_action(_char);
        
        if (action == GO_DOWN) {
            if (option == HARD) {
                option = EASY;
            } else {
                option++;
            }
        }
        
        if (action == GO_UP) {
            if (option == EASY) {
                option = HARD;
            } else {
                option--;
            }
        }

        if (action == GO_ENTER) {
            option = SELECTED;
        }

        if (action == GO_HELP) {
            option = HELP;
        }

        if (action == GO_QUIT) {
            option = EXIT;
        }
    } while (action == NO_ACTION);
    
    return option;
}