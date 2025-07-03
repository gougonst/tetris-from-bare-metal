#include "monitor.h"

void monitor_init() {
    LCD_setPins(
        MONITOR_DC_ID,
        MONITOR_CS_ID,
        MONITOR_RST_ID,
        MONITOR_SCK_ID,
        MONITOR_MOSI_ID
    );
    LCD_initDisplay();
    LCD_setRotation(0);
    GFX_createFramebuf();
}
