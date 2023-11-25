#include "main.hpp"

// TWatchClass *twatch = nullptr;
// TFT_eSPI *tft = nullptr;
// bool clear_irq = false;
// uint16_t color;
// uint8_t fill_order = 0;
// bool isline = false;
// int16_t last_x, last_y;
// uint16_t point_x, point_y;
// 
// char buf[128];
// void setup() {
//   twatch = TWatchClass::getWatch();
//   tft = twatch->tft_get_instance();

//   Serial.begin(115200);
//   Serial1.begin(9600); // rfid
//   twatch->motor_shake(2, 50);

  // tft->fillScreen(TFT_BLACK);
  // twatch->backlight_set_value(255);

//   Serial.println("Touch Pad Demo (TFT_eSPI)");

//   twatch->hal_auto_update(true, 0);

//   tft->setTextFont(2);
//   tft->setTextColor(TFT_WHITE, TFT_BLACK);
//   tft->drawString("T-Watch Touch Test", 62, 90);

//   twatch->button_bind_event(TWATCH_BTN_1, BUTTON_CLICK, [](void *param) { clear_irq = true; Serial.println("button1");});
//   // twatch->button_bind_event(TWATCH_BTN_2, BUTTON_CLICK, [](void *param) { clear_irq = true; Serial.println("button2");});
//   // twatch->button_bind_event(TWATCH_BTN_3, BUTTON_CLICK, [](void *param) { clear_irq = true; Serial.println("button3");});
// }

// void loop() {
//   if (xEventGroupGetBits(twatch->_Hal_IRQ_event) & TOUCH_IRQ_BIT) {
//     xEventGroupClearBits(twatch->_Hal_IRQ_event, TOUCH_IRQ_BIT);
//     point_x = twatch->touch_getX();
//     point_y = twatch->touch_getY();
// 	backend();
//     sprintf(buf, "Hello World");
//     sprintf(buf, "ce sont les zouzous");
//     tft->drawString(buf, 80, 118);
//     if (!isline) {
//       tft->drawPixel(point_x, point_y, color);
//       isline = true;
//     } else {
//       tft->drawLine(point_x, point_y, last_x, last_y, color);
//     }
//     last_x = point_x;
//     last_y = point_y;
//   } else {
//     color = random(TFT_BLACK, TFT_WHITE);
//     isline = false;
//   }
//   delay(20);
//   if (clear_irq) // Clear the screen
//   {
//     clear_irq = false;
//     if (fill_order == 0) {
//       tft->fillScreen(TFT_RED);
//       fill_order++;
//     } else if (fill_order == 1) {
//       tft->fillScreen(TFT_GREEN);
//       fill_order++;
//     } else if (fill_order == 2) {
//       tft->fillScreen(TFT_BLUE);
//       fill_order++;
//     } else if (fill_order == 3) {
//       tft->fillScreen(TFT_WHITE);
//       fill_order++;
//     } else {
//       tft->fillScreen(TFT_BLACK);
//       fill_order = 0;
//     }
//   }
// }

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <TWatch_hal.h>

// Paramètres Wi-Fi
const char* ssid = "Manufacturing Lab";
const char* password = "Manufacturing2023!";

TWatchClass *twatch = nullptr;
TFT_eSPI *tft = nullptr;

bool clear_irq = false;
uint16_t color;
uint8_t fill_order = 0;
bool isline = false;
int16_t last_x, last_y;
uint16_t point_x, point_y;

void setup() {
  Serial.printf("Hello World");
  twatch = TWatchClass::getWatch();
  tft = twatch->tft_get_instance();

  Serial.begin(115200);

  tft->fillScreen(TFT_BLACK);
  twatch->backlight_set_value(255);
  twatch->hal_auto_update(true, 0);

  bool ok = false;
  // Connexion au Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    ok = true;
    // tft->fillScreen(TFT_BLACK);
    // tft->setTextFont(2);
    // tft->setTextColor(TFT_GREEN, TFT_BLACK);
    // tft->drawString("Connecting to WiFi...", 150, 150);
  }

  if (ok) 
  {
    tft->fillScreen(TFT_BLACK);
    tft->setTextFont(2);
    tft->setTextColor(TFT_GREEN, TFT_BLACK);
     tft->drawString("Connecting to WiFi...", 50, 100);
  }

  // Afficher un message une fois connecté
  // tft->fillScreen(TFT_BLACK);
  // tft->setTextFont(2);
  // tft->setTextColor(TFT_WHITE, TFT_BLACK);
  // tft->drawString("Connected to WiFi", 50, 50);
  
  // Effectuer une requête HTTP
  HTTPClient http;
  http.begin("http://mes.42lausanne.ch/api/v1/Device");
  int httpCode = http.GET();

  if (httpCode > 0) {
    String response = http.getString();
    Serial.println("fonctionne ptt");
    // Traiter la réponse ici
  } else {
    Serial.println("Error in HTTP request");
  }

  http.end();
}

void loop() {
  // Le code pour gérer les interactions utilisateur et les mises à jour d'affichage
}