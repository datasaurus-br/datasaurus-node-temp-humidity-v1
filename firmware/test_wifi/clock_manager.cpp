#include "clock_manager.h"

ClockManager clockManager;

void ClockManager::setup() {
    configTime(
        -3 * 3600,
        0,
        "pool.ntp.org",
        "time.google.com"
    );

    Serial.println("Sincronizando relógio...");

    struct tm timeInfo;

    if (getLocalTime(&timeInfo, 10000)) {
        synced = true;

        Serial.println("Relógio sincronizado.");

        Serial.print("Data/hora: ");
        Serial.println(getDateTime());
    } else {
        synced = false;

        Serial.println("Falha ao sincronizar relógio.");
    }
}

bool ClockManager::isSynced() {
    return synced;
}

time_t ClockManager::getTimestamp() {
    return time(nullptr);
}

String ClockManager::getDateTime() {
    struct tm timeInfo;

    if (!getLocalTime(&timeInfo)) {
        return "";
    }

    char buffer[30];

    strftime(
        buffer,
        sizeof(buffer),
        "%Y-%m-%d %H:%M:%S",
        &timeInfo
    );

    return String(buffer);
}