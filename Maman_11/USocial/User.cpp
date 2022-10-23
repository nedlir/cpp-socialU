#include "User.h"

User::User()
{
    id = 0;
}

User::~User()
{
    for (auto const &_post : posts)
        delete _post;

    posts.clear();

    for (auto const &_message : receivedMessages)
        delete _message;

    receivedMessages.clear();
}

inline unsigned long User::getId() const
{
    return id;
}

inline const std::string User::getName() const
{
    return name;
}

void User::addFriend(User *_user)
{
    if (isFriendOf(_user))
        std::cout << "User " << _user->name << " (" << _user->id << ") is already in your friends list." << std::endl;
    else
        friends.push_back(_user->id);
}

void User::removeFriend(User *_user)
{
    if (isFriendOf(_user))
        friends.remove(_user->id);
    else
        std::cout << "User " << _user->name << " (" << _user->id << ") is not in your friends list." << std::endl;
}

void User::post(std::string _text, Media *_media)
{
    if (_media != nullptr)
        posts.push_back(new Post(_text, _media));
    else
        posts.push_back(new Post(_text));
}

inline const std::list<Post *> User::getPosts() const
{
    return posts;
}

void User::viewFriendsPosts() const
{
    std::cout << name << " viewing posts by friends:" << std::endl;
    for (auto const &friendId : friends)
    {
        try
        {
            auto myFriend = social_network->getUserById(friendId);
            std::cout << myFriend->name << " posted:" << std::endl;
            for (auto const &_post : myFriend->posts)
                _post->display();
        }
        catch (const std::exception &e)
        {
            std::cout << "error: " << e.what() << std::endl;
        }
    }
    std::cout << "=============" << std::endl;
}

inline void User::receiveMessage(Message *_message)
{
    receivedMessages.push_back(_message);
}

void User::sendMessage(User *_user, Message *_message)
{
    if (isFriendOf(_user))
        _user->receiveMessage(_message);
    else
        throw std::runtime_error("User is not in your friends list.");
}

void User::viewReceivedMessages() const
{
    for (auto const &_message : receivedMessages)
        _message->display();
}

bool User::isFriendOf(User *_user) const
{
    // search for user in friends list
    for (auto const &_friendId : friends)
        if (_friendId == _user->getId())
            return true;

    // user not found in friends list
    return false;
}