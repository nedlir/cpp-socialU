#ifndef _USOCIAL_H_
#define _USOCIAL_H_

#include <iostream>
#include <map>
#include <string>

class User;
class BusinessUser;

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

    User *registerUser(std::string _name, bool _isBusiness = false);
    void removeUser(User *_user);
    User *getUserById(unsigned long _id);
};

#endif // _USOCIAL_H_