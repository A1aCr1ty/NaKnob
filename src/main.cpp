#include <Arduino.h>
#include "RGB.h"
#include "app/app.h"
#include "app/ui/ui.h"
#include "usb_cdc.h"
#include "hal/hal.h"

void setup()
{
  HAL::Init();
  strip_init();
  //HWSerial.begin(115200);
  display_init();
  //ui_init();
  //knob_init(push_handler);
  App_Init();
  INIT_DONE();
}

void loop()
{
  unsigned long currentMillis = millis();
  strip_start(currentMillis);

  HAL::Update();
}
