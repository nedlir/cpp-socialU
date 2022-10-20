#include "USocial.h"

USocial::USocial()
{
    user_id;
}

USocial::~USocial()
{
    //() for each DELETE all the users
}

User *USocial::registerUser(std::string _name, bool _isBusiness)
{
    if (_name <= 0)
        return nullptr;

    // create new user
    User *user;
    if (_isBusiness)
        user = new User();
    else
        user = new User();

    // init user details
    user->social_network = this;
    user->name = _name;
    user_id++;
    user->id = user_id;
    user->network = this;

    // add users map
    users.insert(std::pair<unsigned long, User *>(user->id, user));

    return user;
}
void USocial::removeUser(User *_user)
{
    auto it = users.find(user->id);

    // if we have found the user id we validate that the name is also identical before erasing
    if (it != users.end() && user->name == it->second->name)
    {
        users.erase(it->first);
        delete it->second;
    }
}
User *USocial::getUserById(unsigned long _user_id)
{
    return nullptr;
}