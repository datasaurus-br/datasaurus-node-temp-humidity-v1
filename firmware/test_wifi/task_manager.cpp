#include "task_manager.h"

void TaskManager::addTask(
    unsigned long interval,
    std::function<void()> callback
) {
    Task task;

    task.interval = interval;
    task.lastRun = millis();
    task.callback = callback;

    tasks.push_back(task);
}

void TaskManager::loop() {
    unsigned long now = millis();

    for (Task& task : tasks) {
        if (now - task.lastRun >= task.interval) {
            task.lastRun = now;
            task.callback();
        }
    }
}