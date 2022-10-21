#include "User.h"
#include <algorithm>
#include <iostream>
#include <exception>

User::User()
{
    id = 0;
}

User::~User()
{
    // destroy posts - the only "new" objects the User created
    for (auto &&post : posts)
        delete post;

    // also destroy messages - each user holds pointers to his own recieved messages
    for (auto &&message : receivedMessages)
        delete message;
}

inline unsigned long User::getId() const
{
    return id;
}

const inline std::string User::getName() const
{
    return name;
}

void User::addFriend(User *_user)
{
    friends.push_back(_user->id);
}

void User::removeFriend(User *_user)
{
    auto _it = find(friends.begin(), friends.end(), _user->id);
    if (_it != friends.end())
    {
        friends.remove(_user->id);
    }
}

void User::post(std::string _text)
{
    Post *post = new Post(_text);
    posts.push_back(post);
}

void User::post(std::string _text, Media *_media)
{
    Post *_post = new Post(_text, _media);
    posts.push_back(_post);
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
            for (auto const &post : myFriend->posts)
                post->display();
        }
        catch (const std::exception &e)
        {
            std::cout << "error: " << e.what() << std::endl;
        }
    }
    std::cout << "=============" << std::endl;
}

void User::receiveMessage(Message *_message)
{
    receivedMessages.push_back(_message);
}

void User::sendMessage(User *_user, Message *_message)
{
    auto _it = find(friends.begin(), friends.end(), _user->id);
    if (_it != friends.end())
        _user->receiveMessage(_message);
    else
        throw std::runtime_error("You tried sending a message to a user who is not your friend!");
}

void User::viewReceivedMessages() const
{
    for (auto const &message : receivedMessages)
        message->display();
}