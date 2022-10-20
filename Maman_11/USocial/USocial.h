#ifndef _USOCIAL_H_
#define _USOCIAL_H_

#include <map>

#include "User.h"

class User;

class USocial
{

private:
    unsigned long user_id;
    std::map<unsigned long, User *> users;

public:
    // constructor
    USocial();

    // destructor
    ~USocial();

    // functions
    User *registerUser(std::string _name, bool _isBusiness);
    void removeUser(User *_user);
    User *getUserById(unsigned long _user_id);
};

#endif // _USOCIAL_H_