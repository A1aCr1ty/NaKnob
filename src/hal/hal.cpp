
#include "hal.h"
#include "lvgl.h"
#define DISP_BUF_SIZE        CONFIG_SCREEN_BUFFER_SIZE

extern lv_color_t* disp_draw_buf;

void HAL::Init()
{
    Serial.begin(115200);

    // Move the malloc process to Init() to make sure that the largest heap can be used for this buffer.
    disp_draw_buf = static_cast<lv_color_t*>(malloc(DISP_BUF_SIZE * sizeof(lv_color_t)));
    if (disp_draw_buf == nullptr)
        LV_LOG_WARN("lv_port_disp_init malloc failed!\n");

    motor_init();
    knob_init();
}


void HAL::Update()
{
    __IntervalExecute(HAL::knob_update(), 10);
    // HAL::motor_update();
}
