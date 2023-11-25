#ifndef MAIN_HPP
#define MAIN_HPP

#include <Arduino.h>
#include <TWatch_hal.h>
#include <iostream>
#include <string>
//"TWatch_config.h" needs to be configured in the library for the first time
// This routine needs to annotate the LVGL GUI

#include "backend/backend.hpp"

using namespace std;

void	setup();
void	loop();

#endif