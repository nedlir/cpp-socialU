#include "USocial.h"
#include "User.h"
#include "BusinessUser.h"
#include <iostream>

USocial::USocial()
{
    user_id = 0;
}

USocial::~USocial()
{
    for (const auto &user_element : users)
        delete user_element.second;
    users.clear();
}

User *USocial::registerUser(std::string _name, bool _isBusiness)
{
    if (_name.length() <= 0)
    {
        throw std::runtime_error("User name is invalid.");
    }

    User *user;
    if (_isBusiness)
        user = new BusinessUser();
    else
        user = new User();

    // init user and add to map
    user_id++;
    user->id = user_id;
    user->name = _name;
    user->social_network = this;
    users.insert(std::pair<unsigned long, User *>(user->id, user));

    return user;
}

void USocial::removeUser(User *_user)
{
    if (_user == nullptr || _user->id == 0) // user object created outside the network
    {
        std::cout << "User initialized outside the network." << std::endl;
        return;
    }
    else if (users.find(_user->id) == users.end())
    {
        std::cout << "User not found in network." << std::endl;
        return;
    }
    else
    {
        users.erase(_user->id);
        std::cout << "User " << _user->id << " removed from the network." << std::endl;
    }
}

User *USocial::getUserById(unsigned long _id)
{
    try
    {
        return users.at(_id);
    }
    catch (std::out_of_range)
    {
        std::cout << "User id: " << _id << " not found." << std::endl;
        return nullptr;
    }
}