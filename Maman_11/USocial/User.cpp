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
    {
        this->friends.remove(_user->id);
        _user->friends.remove(this->id); // remove this use from the argument user he just unfriended
    }

    else
        std::cout << "User " << _user->name << " (" << _user->id << ") is not in your friends list." << std::endl;
}

void User::post(std::string _text)
{
    posts.push_back(new Post(_text));
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
    User *_friend;
    for (auto const &_friendId : friends)
    {
        _friend = (User *)(social_network->getUserById(_friendId));
        for (auto const &_post : _friend->posts)
            _post->display();
    }
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

std::string User::addUserNameToString(const std::string &_origin, const std::string &_text_type)
{
    return "HHH";
}