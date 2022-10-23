#ifndef _USER_H_
#define _USER_H_

#include <algorithm>
#include <exception>
#include <iostream>
#include <list>
#include <string>

#include "Post.h"
#include "Message.h"
#include "USocial.h"

class USocial;

class User
{
    friend class USocial;

private:
    // functions
    void encodeUserNameToPost(std::string &_origin);

protected:
    unsigned long id;
    std::string name;
    std::list<unsigned long> friends;
    std::list<Post *> posts;
    std::list<Message *> receivedMessages;
    USocial *social_network;

    // functions
    bool isFriendOf(User *_user) const;

    // constructor
    User();

    // destructor
    ~User();

public:
    // functions
    unsigned long getId() const;
    const std::string &getName() const;
    void addFriend(User *_user) throw();
    void removeFriend(User *_user);
    void post(std::string _text);
    void post(std::string _text, Media *_media);
    const std::list<Post *> getPosts() const;
    void viewFriendsPosts() const;
    void receiveMessage(Message *_message);
    virtual void sendMessage(User *_user, Message *_message);
    void viewReceivedMessages() const;
};

#endif // _USER_H_