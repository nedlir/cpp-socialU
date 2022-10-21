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

protected:
    unsigned long id;
    std::string name;
    std::list<unsigned long> friends;
    std::list<Post *> posts;
    std::list<Message *> receivedMessages;
    USocial *social_network;

    User();
    ~User();

public:
    unsigned long getId() const;
    const std::string getName() const;
    void addFriend(User *);
    void removeFriend(User *);
    void post(std::string);
    void post(std::string, Media *);
    const std::list<Post *> getPosts() const;
    void viewFriendsPosts() const;
    void receiveMessage(Message *);
    virtual void sendMessage(User *, Message *);
    void viewReceivedMessages() const;
};

#endif // _USER_H_