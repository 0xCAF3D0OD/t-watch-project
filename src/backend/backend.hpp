#ifndef BACKEND_HPP
#define BACKEND_HPP
#include "Arduino.h"
#include "../main.hpp"

void	backend(TFT_eSPI *tft, TWatchClass *twatch);
// void    buttons(TFT_eSPI *tft, TWatchClass *twatch);
void    wifi(TFT_eSPI *tft);
// rfid.cpp
void	rfid();

#endif