#ifndef CLOCK_MANAGER_H
#define CLOCK_MANAGER_H

#include <Arduino.h>
#include <time.h>

class ClockManager {
public:
    void setup();

    bool isSynced();

    time_t getTimestamp();

    String getDateTime();

private:
    bool synced = false;
};

extern ClockManager clockManager;

#endif