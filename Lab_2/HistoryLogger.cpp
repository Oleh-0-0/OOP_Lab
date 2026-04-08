#include "HistoryLogger.h"
#include <fstream>
#include <chrono>
#include <ctime>

void HistoryLogger::log(const std::string& user, const std::string& action) {
    std::ofstream ofs(logFile, std::ios::app);
    if (!ofs.is_open()) return;

    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    ofs << std::ctime(&t) << " | " << user << " | " << action << std::endl;
}
