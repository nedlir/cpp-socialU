#include "USocial.h"

#include "BusinessUser.h"
#include "User.h"

USocial::USocial()
{
    user_id = 1;
}

USocial::~USocial()
{
    for (auto &&user_element : users)
        delete user_element.second;

    users.clear(); // deletes all first elements (non-object primitive type)
}

User *USocial::registerUser(std::string _name, bool _isBusiness)
{
    if (_name.empty()) // invalid name
        _name = "Anonymous User";

    User *_user;
    if (_isBusiness)
        _user = new BusinessUser();
    else
        _user = new User();

    // init user and add to map
    _user->id = user_id;
    user_id++;
    _user->name = _name;
    _user->social_network = this;
    users.insert(std::pair<unsigned long, User *>(_user->id, _user));

    return _user;
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
        std::cout << "User " << _user->name << " (" << _user->id << ") removed from the network." << std::endl;
    }
}

User *USocial::getUserById(unsigned long _id) const
{
    if (users.find(_id) == users.end())
    {
        std::cout << "User not found in network." << std::endl;
        return nullptr;
    }
    else
        return users.at(_id);
}