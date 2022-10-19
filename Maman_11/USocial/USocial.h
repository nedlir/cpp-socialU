#ifndef _USOCIAL_H_
#define _USOCIAL_H_

#include <map>
#include <string>
#include "User.h"

class User;

class USocial
{
    // Friend classes:
    friend class USocial;

private:
    unsigned long user_id;

    std::map<unsigned long, User *> users;

public:
    /* constructors */
    USocial(){};

    /* copy constructors */
    // not allowed (there can't be different networks for same user), destroy original
    USocial(const USocial &) = delete;

    /*destructor*/
    ~USocial(){};

    /* class functions */
    // registers a new user to the network
    User *registerUser(const std::string &username, bool isBusiness = false);

    // removes a user from the network
    void removeUser(User *user);

    // returns a user based on his id
    User *getUserById(unsigned long user_id) const;
};

#endif // _USOCIAL_H_