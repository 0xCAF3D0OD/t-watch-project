#include "Arduino.h"
#include "backend.hpp"

// struct ButtonParameters {
//  TWatchClass *twatch;
//  TFT_eSPI *tft;
// };

// void btn1_click(void *param) {
//  ButtonParameters *params = (ButtonParameters *)param;
//  Serial.println("BTN1 Click");
//  params->tft->drawString("BTN1 Click", 80, 118);
//  params->twatch->motor_shake(2, 50);
// }

// void btn2_click(void *param) {
//  ButtonParameters *params = (ButtonParameters *)param;
//  Serial.println("BTN2 Click");
//  params->tft->drawString("BTN2 Click", 80, 118);
//  params->twatch->motor_shake(2, 50);
// }

// void btn3_click(void *param) {
//  ButtonParameters *params = (ButtonParameters *)param;
//  Serial.println("BTN3 Click");
//  params->tft->drawString("BTN3 Click", 80, 118);
//  params->twatch->motor_shake(2, 50);
// }

// void    buttons(TWatchClass *twatch, TFT_eSPI *tft) {
//     Serial.println("salut World");
    
//     tft->setTextFont(2);
//     tft->setTextColor(TFT_BLACK, TFT_WHITE);
//     tft->drawString("T-Watch Button Test", 62, 90);
    
//     ButtonParameters params = {twatch, tft};
    
//     twatch->button_bind_event(TWATCH_BTN_1, BUTTON_CLICK, btn1_click, &params);
//     twatch->button_bind_event(TWATCH_BTN_2, BUTTON_CLICK, btn2_click, &params);
//     twatch->button_bind_event(TWATCH_BTN_3, BUTTON_CLICK, btn3_click, &params);
// }


void buttons(TWatchClass *twatch, TFT_eSPI *tft) {
    Serial.println("salut World");
 
//  tft->setTextFont(2);
//  tft->setTextColor(TFT_BLACK, TFT_WHITE);
//  tft->drawString("T-Watch Button Test", 62, 90);
 
//  ButtonParameters params = {twatch, tft};
 
//  twatch->button_bind_event(TWATCH_BTN_1, BUTTON_CLICK, btn1_click, &params);
//  twatch->button_bind_event(TWATCH_BTN_2, BUTTON_CLICK, btn2_click, &params);
//  twatch->button_bind_event(TWATCH_BTN_3, BUTTON_CLICK, btn3_click, &params);
}