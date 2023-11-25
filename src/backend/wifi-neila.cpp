#include <WiFi.h>
#include <HTTPClient.h>
// #include <ArduinoJson.h>
#include <TWatch_hal.h>

// Paramètres Wi-Fi
const char* ssid = "Manufacturing Lab";
const char* password = "Manufacturing2023!";

void wifi(TFT_eSPI *tft) {
  Serial.println("Hello World");
  
  bool ok = false;
  // Connexion au Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    ok = true;
  }

  if (ok) 
  {
    tft->fillScreen(TFT_BLACK);
    tft->setTextFont(2);
    tft->setTextColor(TFT_GREEN, TFT_BLACK);
    tft->drawString("Connected to WiFi", 50, 100);
  }
  
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
