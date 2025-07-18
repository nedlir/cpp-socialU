#include "User.h"

User::User()
{
    id = 0;
}

User::~User()
{
    // remove this user from his friends list
    User *_friend;
    for (auto const &_friendId : friends)
    {
        _friend = (User *)(social_network->getUserById(_friendId));
        _friend->removeFriend(this);
    }

    // remove all other users from this friends list
    friends.clear();

    // delete all user posts
    for (auto &_post : posts)
        delete _post;

    // delete all received messages
    for (auto &_message : receivedMessages)
        delete _message;
}

inline unsigned long User::getId() const
{
    return id;
}

inline const std::string &User::getName() const
{
    return name;
}

void User::addFriend(User *_user) throw()
{
    if (!isFriendOf(_user))
        friends.push_back(_user->id);
    else
        throw std::runtime_error("User is already in your friends list.");
}

void User::removeFriend(User *_user)
{
    if (isFriendOf(_user))
    {
        this->friends.remove(_user->id);
        _user->friends.remove(this->id); // remove this user from the argument user he just unfriended
    }

    else
        std::cout << "User " << _user->name << " (" << _user->id << ") is not in your friends list." << std::endl;
}

void User::post(std::string _text)
{
    if (_text.empty())
        _text = "Empty Post";

    encodeUserNameToPost(_text);

    posts.push_back(new Post(_text));
}

void User::post(std::string _text, Media *_media)
{

    if (_text.empty())
        _text = "Empty Post";

    encodeUserNameToPost(_text);

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

// concatenates the name of the user to the post
void User::encodeUserNameToPost(std::string &_origin)
{
    _origin = _origin + "\n";
    _origin = _origin + "Posted by ";
    _origin = _origin + name;
}