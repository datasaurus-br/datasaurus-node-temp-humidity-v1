#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <Arduino.h>
#include <vector>
#include <functional>

class TaskManager {
public:
    void addTask(unsigned long interval, std::function<void()> callback);
    void loop();

private:
    struct Task {
        unsigned long interval;
        unsigned long lastRun;
        std::function<void()> callback;
    };

    std::vector<Task> tasks;
};

#endif