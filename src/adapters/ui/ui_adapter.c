#include "ui_adapter.h"

#ifdef _WIN32

extern UIAdapterInterface ui_windows;
#define ACTIVE_ADAPTER &ui_windows

#endif


UIAdapterInterface* get_ui_adapter() {
    return ACTIVE_ADAPTER;
}