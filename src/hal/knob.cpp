
#include "hal.h"
#include <Arduino.h>
#include "config.h"

static volatile int16_t EncoderDiff = 0;

static ButtonEvent EncoderPush(500);
extern int rgb_flag;
bool HAL::encoder_is_pushed(void)
{
    if (digitalRead(PUSH_BUTTON_PIN) == LOW)
    {
        return true;
    }
    return false;
}

void HAL::knob_update(void)
{
    EncoderPush.EventMonitor(encoder_is_pushed());
}
static void Encoder_PushHandler(ButtonEvent *btn, int event)
{

    if (event == ButtonEvent::EVENT_PRESSED)
    {
        rgb_flag = 1;
        // HAL::Buzz_Tone(500, 20);
        // EncoderDiffDisable = true;
        ;
    }
    else if (event == ButtonEvent::EVENT_RELEASED)
    {
        // HAL::Buzz_Tone(700, 20);
        // EncoderDiffDisable = false;
        ;
    }
    else if (event == ButtonEvent::EVENT_LONG_PRESSED)
    {
        // HAL::Audio_PlayMusic("Shutdown");
        // HAL::Power_Shutdown();
        rgb_flag = 2;
        ;
    }
    else if (event == ButtonEvent::EVENT_DOUBLE_CLICKED)
    {
        rgb_flag = 0;
        ;
    }
}

void HAL::knob_init()
{
    pinMode(PUSH_BUTTON_PIN, INPUT_PULLUP);
    EncoderPush.EventAttach(Encoder_PushHandler);
    // attachInterrupt(CONFIG_ENCODER_A_PIN, Encoder_A_IrqHandler, CHANGE);
    // push_button.EventAttach(button_handler);
}