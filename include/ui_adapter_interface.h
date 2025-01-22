#ifndef UI_ADAPTER_INTERFACE_H
#define UI_ADAPTER_INTERFACE_H

typedef enum {
    NO_ACTION,
    GO_UP,
    GO_DOWN,
    GO_LEFT,
    GO_RIGHT,
    GO_ENTER,
    GO_HELP,
    GO_QUIT
} key_action;

typedef struct {
    void (*init_screen)(void);
    void (*print_text)(int y, int x, const char *text);
    int  (*get_char)(void);
    key_action (*get_key_action)(int key);
    void (*set_key_action)(int key, key_action action);
    void (*clean_screen)(void);
    void (*end_screen)(void);
} UIAdapterInterface;


UIAdapterInterface* get_ui_adapter();

#endif