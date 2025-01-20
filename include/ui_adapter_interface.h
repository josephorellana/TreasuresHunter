#ifndef UI_ADAPTER_INTERFACE_H
#define UI_ADAPTER_INTERFACE_H

typedef struct {
    void (*init_screen)(void);
    void (*print_text)(int y, int x, const char *text);
    void (*clean_screen)(void);
    void (*end_screen)(void);
} UIAdapterInterface;


UIAdapterInterface* get_ui_adapter();

#endif