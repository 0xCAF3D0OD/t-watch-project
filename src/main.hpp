#ifndef MAIN_HPP
#define MAIN_HPP

#include <Arduino.h>
#include <TWatch_hal.h>
#include <iostream>
#include <string>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "backend/class/User.hpp"
#include "backend/class/Device.hpp"
#include "backend/class/Equipment.hpp"
#include "backend/class/Notification.hpp"

class User;
class Device;
class Equipment;
class Notification;

//"TWatch_config.h" needs to be configured in the library for the first time
// This routine needs to annotate the LVGL GUI

#include "backend/backend.hpp"

using namespace std;

void	setup();
void	loop();

#endif