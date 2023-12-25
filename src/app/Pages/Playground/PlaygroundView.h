#ifndef __PLAGROUND_VIEW_H
#define __PLAGROUND_VIEW_H
#include <Arduino.h>
#include "app/app.h"

#include "../Page.h"

// 控制画面跳转


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
        void UpdatePlaygroundView(PlaygroundMotorInfo *info);
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
        void SuperDialView(void);
    };

}

#endif // !__VIEW_H