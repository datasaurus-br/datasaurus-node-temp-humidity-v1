#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>

void wifiSetup(const char* ssid, const char* password);
void wifiLoop();
bool wifiIsConnected();
String wifiGetIP();
String wifiGetMac();

#endif