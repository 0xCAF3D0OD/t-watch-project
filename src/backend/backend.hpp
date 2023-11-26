#ifndef BACKEND_HPP
#define BACKEND_HPP
#include "Arduino.h"
#include "../main.hpp"

void	backend(TFT_eSPI *tft, TWatchClass *twatch);
// void    buttons(TFT_eSPI *tft, TWatchClass *twatch);
void    wifi(TFT_eSPI *tft);
// rfid.cpp
void	rfid();

// postRequest.cpp
void    postRequestNotification(string url, Notification &notification);
void    postRequestPairing(const string &userId, const string &deviceId);
void	postRequestPairingDelete(const string& deviceId);

// getRequest.cpp
void	getRequestUser(std::string url, User &user);
void	getRequestDevise(std::string url, Device &device);
void	getRequestEquipment(std::string url, Equipment &equipment);
void	getRequestNotification(std::string url, Notification &notification);


#endif