#ifndef __PLAGROUND_VIEW_H
#define __PLAGROUND_VIEW_H
#include <Arduino.h>
#include "hal/motor.h"

#include "../Page.h"

enum PLAYGROUND_MODE
{
    PLAYGROUND_MODE_UNBOUND = MOTOR_UNBOUND_NO_DETENTS,
    PLAYGROUND_MODE_BOUND = MOTOR_BOUND_0_12_NO_DETENTS,
    PLAYGROUND_MODE_MULTI_RCV = MOTOR_COARSE_DETENTS,
};

typedef struct
{
    int32_t xkonb_value;
    int32_t motor_pos;
    int32_t angle_offset;
} PlaygroundMotorInfo;

namespace Page
{

    class PlaygroundView
    {
    public:
        void Create(lv_obj_t *root);
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
        void CreateBoundView(void);
        void BoundView(void);
    };

}

#endif // !__VIEW_H