#ifndef HISTORYLOGGER_H
#define HISTORYLOGGER_H

#include <string>

class HistoryLogger {
private:
    std::string logFile = "history.log";
public:
    HistoryLogger() = default;
    void log(const std::string& user, const std::string& action);
};

#endif
