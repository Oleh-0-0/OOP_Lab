#ifndef AUTH_H
#define AUTH_H

#include <string>

class Auth {
private:
    std::string cfgFile = "admin.cfg";
    std::string salt = "SALT"; 

    std::string hashPassword(const std::string& pwd) const;

public:
    Auth() = default;
    bool verify(const std::string& password);
    bool initIfMissing();
    bool changePassword(const std::string& oldPwd, const std::string& newPwd);
};

#endif
