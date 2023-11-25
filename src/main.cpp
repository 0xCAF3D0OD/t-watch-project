#include "main.hpp"
#include "backend/backend.hpp"

TWatchClass *twatch = nullptr;
TFT_eSPI *tft = nullptr;

char buf[128];
int analogValue = 0; 

void setup() {
  analogValue = analogRead(0);
  twatch = TWatchClass::getWatch();
  tft = twatch->tft_get_instance();

  Serial.begin(115200);
  twatch->motor_shake(2, 50);

  tft->fillScreen(TFT_BLACK);
  twatch->backlight_set_value(255);

  Serial.println("Touch Pad Demo (TFT_eSPI)");

  twatch->hal_auto_update(true, 0);

  tft->setTextFont(2);
  tft->setTextColor(TFT_WHITE, TFT_BLACK);
  tft->drawString("T-Watch Touch Test", 62, 90);
  backend();
}

void loop() {
  if (xEventGroupGetBits(twatch->_Hal_IRQ_event) & TOUCH_IRQ_BIT) {
    xEventGroupClearBits(twatch->_Hal_IRQ_event, TOUCH_IRQ_BIT);
    tft->drawString(buf, 80, 118);
  }
  Serial.print("1");
  delay(20);
}
