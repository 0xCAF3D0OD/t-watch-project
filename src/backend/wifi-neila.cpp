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
    // tft->drawString("Connected to WiFi", 50, 30);

	// test User //////////////////////////////////////////////////////////
	// User user;
	// getRequestUser("http://mes.42lausanne.ch/api/v1/User/001", user);
	// tft->drawString(user.getId().c_str(), 50, 70);
	// tft->drawString(user.getCardID().c_str(), 50, 100);
	// tft->drawString(user.getName().c_str(), 50, 130);

	// test Device //////////////////////////////////////////////////////////
	// Device device;
	// getRequestDevise("http://mes.42lausanne.ch/api/v1/Device/123", device);
	// tft->drawString(device.getId().c_str(), 50, 70);
	// tft->drawString(device.getDescription().c_str(), 50, 100);
	// tft->drawString(device.getPairedUserID().c_str(), 50, 130);

	// test Equipment //////////////////////////////////////////////////////////
	// Equipment equipment;
	// getRequestEquipment("http://mes.42lausanne.ch/api/v1/Equipment/25208881", equipment);
	// tft->drawString(equipment.getId().c_str(), 50, 70);
	// tft->drawString(equipment.getDescription().c_str(), 50, 100);
	// tft->drawString(equipment.getPairedUserID().c_str(), 50, 130);

	// test Notification //////////////////////////////////////////////////////////
	// Notification notification;
	// getRequestNotification("http://mes.42lausanne.ch/api/v1/Notification/354", notification);
	// tft->drawString(notification.getEqtID().c_str(), 50, 70);
	// tft->drawString(notification.getTitle().c_str(), 50, 90);
	// tft->drawString(notification.getDescription().c_str(), 50, 110);
	// tft->drawString(std::to_string(notification.getPriority()).c_str(), 50, 130);
	// tft->drawString(std::to_string(notification.getID()).c_str(), 50, 150);
	// if (notification.getAcked())
	// 	tft->drawString("true", 50, 170);
	// else
	// 	tft->drawString("false", 50, 170);
  }
}
