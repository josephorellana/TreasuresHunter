#ifndef UI_ADAPTER_H
#define UI_ADAPTER_H

#include "ui_adapter_interface.h"

typedef struct {
    int go_up;
    int go_down;
    int go_left;
    int go_right;
    int go_enter;
    int go_help;
    int go_quit;
} KeyActionSettings;

#endif