#ifndef __CONFIG_H__
#define __CONFIG_H__

// 屏幕驱动
#define SCLK 12
#define MOSI 11
#define TFT_CS 10
#define TFT_BLK 13
#define TFT_DC 14
#define TFT_RST 9

// FOC 驱动
#define MO1 17
#define MO2 16
#define MO3 15

#define MT6701_SDA 1
#define MT6701_SCL 2
#define MT6701_SS 42


#define CONFIG_SCREEN_HOR_RES       240
#define CONFIG_SCREEN_VER_RES       240
#define CONFIG_SCREEN_BUFFER_SIZE   (CONFIG_SCREEN_HOR_RES * CONFIG_SCREEN_VER_RES /2)

#define PUSH_BUTTON_PIN 5

#define LVGL_RUNNING_CORE 0
#define ESP32_RUNNING_CORE 1
#endif 