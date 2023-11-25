#include "main.hpp"
#include "backend/backend.hpp"

TWatchClass *twatch = nullptr;
TFT_eSPI *tft = nullptr;

bool clear_irq = false;
uint16_t color;
uint8_t fill_order = 0;
bool isline = false;
int16_t last_x, last_y;
uint16_t point_x, point_y;

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
  twatch->motor_shake(2, 50);

  tft->fillScreen(TFT_BLACK);
  twatch->backlight_set_value(255);

  twatch->hal_auto_update(true, 1);

  tft->setTextFont(2);
  tft->setTextColor(TFT_BLACK, TFT_WHITE);
  tft->drawString("T-Watch Button Test", 62, 90);

  twatch->button_bind_event(TWATCH_BTN_1, BUTTON_CLICK, btn1_click, tft);
  twatch->button_bind_event(TWATCH_BTN_2, BUTTON_CLICK, btn2_click, tft);
  twatch->button_bind_event(TWATCH_BTN_3, BUTTON_CLICK, btn3_click, tft);

  backend(tft, twatch);
}

void loop() {
  if (xEventGroupGetBits(twatch->_Hal_IRQ_event) & TOUCH_IRQ_BIT) {
    xEventGroupClearBits(twatch->_Hal_IRQ_event, TOUCH_IRQ_BIT);
    tft->drawString(buf, 80, 118);
  }
  // if (clear_irq) // Clear the screen
  // {
  //   clear_irq = false;
  //   if (fill_order == 0) {
  //     Serial.println("fill_order1: " + fill_order);
  //     twatch->motor_shake(9, 70);
  //     fill_order++;
  //   } else if (fill_order == 1) {
  //     Serial.println("fill_order2: " + fill_order);
  //   // twatch->motor_shake(2, 50);
  //     twatch->motor_shake(9, 70);
  //     fill_order++;
  //   } else {
  //     Serial.println("fill_order3: " + fill_order);
  //     twatch->motor_shake(9, 70);
  //     fill_order = 0;
  //   }
  // }
  // Serial.print("1");
  delay(20);

}

