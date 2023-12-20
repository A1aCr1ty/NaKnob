#ifndef __PLAGROUND_VIEW_H
#define __PLAGROUND_VIEW_H
#include <Arduino.h>
#include "hal/motor.h"

#include "../Page.h"

// 控制画面跳转
enum PLAYGROUND_MODE
{
    PLAYGROUND_MODE_FINE_DETENTS = MOTOR_UNBOUND_FINE_DETENTS,
    PLAYGROUND_MODE_BOUND = MOTOR_BOUND_0_12_NO_DETENTS,
    PLAYGROUND_MODE_ON_OFF = MOTOR_ON_OFF_STRONG_DETENTS,
    PLAYGROUND_MODE_MAX,
};


enum APP_MODE{
    APP_MODE_MIN = PLAYGROUND_MODE_MAX,
    APP_MODE_SUPER_DIAL = APP_MODE_MIN + MOTOR_UNBOUND_FINE_DETENTS,
    APP_MODE_MAX,
};



typedef struct
{
    int32_t xknob_value;
    int32_t motor_pos;
    int32_t angle_offset;
    int32_t knob_direction;
} PlaygroundMotorInfo;

namespace Page
{

    class PlaygroundView
    {
    public:
        void Create(lv_obj_t *root);
        void Delete();
        void UpdateView(PlaygroundMotorInfo *info);
        void SetPlaygroundMode(int16_t mode);
        int16_t playgroundMode;

    public:
        struct
        {
            lv_obj_t *meter;
            lv_meter_scale_t *scale_pot; // 圆点的刻度
            lv_obj_t *lable_value;
            lv_meter_indicator_t *nd_img_circle;
            lv_meter_scale_t *scale_arc; // arc 的刻度
            lv_meter_indicator_t *arc;
            lv_group_t *group;

        } ui;

        struct
        {
            lv_style_t meter;
            lv_style_t ticks;
        } style;

    private:
        void OnOffView(void);
        void BoundZeroView(void);
        void UpdateBackgroundView(PlaygroundMotorInfo *info);
    };

}

#endif // !__VIEW_H