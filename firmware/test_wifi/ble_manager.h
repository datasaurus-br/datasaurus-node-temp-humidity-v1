#ifndef BLE_MANAGER_H
#define BLE_MANAGER_H

#include <Arduino.h>

class BLEManager {
public:
    void setup();
    void loop();

    bool hasNewCredentials();

    String getSSID();
    String getPassword();

    void setSSID(const String& value);
    void setPassword(const String& value);

    void stop();

private:
    String ssid;
    String password;

    bool ssidReceived = false;
    bool passwordReceived = false;
    bool credentialsReceived = false;
};

extern BLEManager bleManager;

#endif