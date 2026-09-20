#include "wifi_manager.h"
#include <WiFi.h>

static const char* wifiSsid;
static const char* wifiPassword;

static unsigned long lastReconnectAttempt = 0;

void wifiSetup(const char* ssid, const char* password) {
    wifiSsid = ssid;
    wifiPassword = password;

    WiFi.mode(WIFI_STA);

    Serial.println("Conectando ao Wi-Fi...");

    WiFi.begin(wifiSsid, wifiPassword);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Wi-Fi conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());

    Serial.print("MAC: ");
    Serial.println(WiFi.macAddress());
}

void wifiLoop() {
    if (WiFi.status() == WL_CONNECTED) {
        return;
    }

    unsigned long now = millis();

    if (now - lastReconnectAttempt < 5000) {
        return;
    }

    lastReconnectAttempt = now;

    Serial.println("Wi-Fi desconectado. Tentando reconectar...");

    WiFi.disconnect();
    WiFi.begin(wifiSsid, wifiPassword);
}

bool wifiIsConnected() {
    return WiFi.status() == WL_CONNECTED;
}

String wifiGetIP() {
    return WiFi.localIP().toString();
}

String wifiGetMac() {
    return WiFi.macAddress();
}