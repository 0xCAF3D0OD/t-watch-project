#include "main.hpp"
lv_obj_t* pg_accueil = lv_obj_create();
TWatchClass *twatch = nullptr;
TFT_eSPI *tft = nullptr;

void btn1_click(void *param) {
  Serial.println("BTN1 Click");
  tft->drawString("BTN1 Click", 80, 118);
  twatch->motor_shake(2, 50);
}
void btn2_click(void *param) {
  Serial.println("BTN2 Click");
  tft->drawString("BTN2 Click", 80, 118);
  twatch->motor_shake(2, 50);
}
void btn3_click(void *param) {
  Serial.println("BTN3 Click");
  tft->drawString("BTN3 Click", 80, 118);
  twatch->motor_shake(2, 50);
}

char buf[128];
int analogValue = 0; 

void set_font(TWatchClass **twatch, TFT_eSPI **tft) {
  (*tft)->setTextFont(2);
  (*tft)->setTextColor(TFT_WHITE, TFT_BLACK);
  (*tft)->drawString("T-Watch Touch Test", 62, 90);
  (*twatch)->motor_shake(2, 50);
  (*tft)->fillScreen(TFT_BLACK);
  (*twatch)->backlight_set_value(255);
  (*twatch)->hal_auto_update(true, 0);
}

void buttonClick(TWatchClass **twatch, TFT_eSPI **tft) {
  (*tft)->setTextFont(2);
  (*tft)->setTextColor(TFT_BLACK, TFT_WHITE);
  (*tft)->drawString("T-Watch Button Test", 62, 90);

  (*twatch)->button_bind_event(TWATCH_BTN_1, BUTTON_CLICK, btn1_click);
  (*twatch)->button_bind_event(TWATCH_BTN_2, BUTTON_CLICK, btn2_click);
  (*twatch)->button_bind_event(TWATCH_BTN_3, BUTTON_CLICK, btn3_click);
}

void setup() {
  analogValue = analogRead(0);
  twatch = TWatchClass::getWatch();
  tft = twatch->tft_get_instance();

  Serial.begin(115200);
  twatch->motor_shake(2, 50);

  tft->fillScreen(TFT_BLACK);
  twatch->backlight_set_value(255);

  Serial.println("Touch Pad Demo (TFT_eSPI)");

  set_font(&twatch, &tft);
  buttonClick(&twatch, &tft);
  backend(tft, twatch);
  lv_example_get_started_1();
  lv_example_textarea_1();
  lv_scr_load();
}

void loop() {

  delay(20);
}
