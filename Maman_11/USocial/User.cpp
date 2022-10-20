#include "User.h"

User::User()
{
}

User::~User()
{
    // for loop delete all new assignments
}

inline unsigned long User::getId()
{
    return id;
}

inline const std::string User::getName() const
{
    return &name;
}

inline void User::addFriend(User *_user)
{
    friends.push_back(user->id);
}

void User::removeFriend(User *user)
{
    auto it = find(friends.begin(), friends.end(), user->id);
    if (it != friends.end())
    {
        friends.remove(user->id);
    }
}

void User::post(std::string text)
{
    Post *post = new Post(text);
    posts.push_back(post);
}

void User::post(std::string text, Media *media)
{
    Post *post = new Post(text, media);
    posts.push_back(post);
}

std::list<Post *> User::getPosts()
{
    return posts;
}

void User::viewFriendsPosts()
{
    std::cout << name << " viewing posts by friends:" << std::endl;
    for (auto const &friendId : friends)
    {
        try
        {
            auto myFriend = us->getUserById(friendId);
            std::cout << myFriend->name << " posted:" << std::endl;
            for (auto const &post : myFriend->posts)
            {
                std::cout << post->getText() << std::endl;
                if (post->getMedia() != NULL)
                {
                    post->getMedia()->display();
                }
            }
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
    auto it = find(friends.begin(), friends.end(), other->id);
    if (it != friends.end())
    {
        _user->receiveMessage(message);
    }
    else
    {
        throw std::runtime_error("You tried sending a message to a user who is not your friend!");
    }
}

void User::viewReceivedMessages()
{
    std::cout << name << " viewing recieved messagess:" << std::endl;
    for (auto const &message : receivedMessages)
    {
        std::cout << message->getText() << std::endl;
    }
    std::cout << "=============" << std::endl;
}
