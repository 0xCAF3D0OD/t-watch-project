#ifndef MAIN_HPP
#define MAIN_HPP

#include <TWatch_hal.h>
//"TWatch_config.h" needs to be configured in the library for the first time
// This routine needs to annotate the LVGL GUI

#include "backend/backend.hpp"
#include "frontend/frontend.hpp"

void	setup();
void	loop();

#endif