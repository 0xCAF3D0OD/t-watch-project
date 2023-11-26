#include "main.hpp"
#include "frontend/frontend.hpp"

TWatchClass *twatch = nullptr;
TFT_eSPI *tft = nullptr;

int currentNotification = 0; // Indice de la notification actuelle
int btn3Pressed = 0;
int btn2Pressed = 0;
int btn1Pressed = 0;

void btn1_click(void *param) {
  btn1Pressed = 1;  
  Serial.println("BTN1 Click");
  tft->drawString("BTN1 Click", 80, 118);
  twatch->motor_shake(2, 50);
}

void btn2_click(void *param) {
  btn2Pressed = 1;
  Serial.println("BTN2 Click");
  tft->drawString("BTN2 Click", 80, 118);
  twatch->motor_shake(2, 50);
    // Défilement vers le haut
  if (currentNotification > 0) {
    currentNotification--;
    lv_obj_align(notification_container, LV_ALIGN_TOP_MID, 0, 50 + (currentNotification * 50));
  }
}

void btn3_click(void *param) {
  Serial.println("BTN3 Click");
  Serial.println(btn3Pressed);
  tft->drawString("BTN3 Click", 80, 118);
  twatch->motor_shake(2, 50);
    // Défilement vers le bas
  if (currentNotification < 4) {
    currentNotification++;
    lv_obj_align(notification_container, LV_ALIGN_TOP_MID, 0, 50 + (currentNotification * 50));
  }
}

void setup() {
  // analogValue = analogRead(0);
  twatch = TWatchClass::getWatch();
  tft = twatch->tft_get_instance();

  Serial.begin(115200);
  twatch->motor_shake(2, 50);

  tft->fillScreen(TFT_BLACK);
  twatch->backlight_set_value(255);

  set_font(&twatch, &tft);
  buttonClick(&twatch, &tft);
  backend(tft, twatch);
  front_ui();
}

void loop() {
  delay(20);
}
