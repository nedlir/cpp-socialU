/*
This class represents the social network.
*/
#include <map>
#include "USocial.h"

USocial::USocial() : user_id(1)
{
}

USocial::~USocial()
{
    for (auto user : users)
        delete user.second;
}

User *registerUser(const std::string &username, bool isBusiness = false)
{
    User *user = new User();
}