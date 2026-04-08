#include "Auth.h"
#include <fstream>
#include <functional>

std::string Auth::hashPassword(const std::string& pwd) const {
    std::hash<std::string> h;
    auto v = h(salt + pwd);
    return std::to_string(v);
}

bool Auth::initIfMissing() {
    std::ifstream ifs(cfgFile);
    if (ifs.is_open()) return true;
   
    std::ofstream ofs(cfgFile, std::ios::trunc);
    if (!ofs.is_open()) return false;
    ofs << hashPassword("admin") << std::endl;
    return true;
}

bool Auth::verify(const std::string& password) {
    std::ifstream ifs(cfgFile);
    if (!ifs.is_open()) return false;
    std::string stored;
    ifs >> stored;
    return stored == hashPassword(password);
}

bool Auth::changePassword(const std::string& oldPwd, const std::string& newPwd) {
    if (!verify(oldPwd)) return false;
    std::ofstream ofs(cfgFile, std::ios::trunc);
    if (!ofs.is_open()) return false;
    ofs << hashPassword(newPwd) << std::endl;
    return true;
}
