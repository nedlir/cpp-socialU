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

public:
    unsigned long getId() const;
    const std::string getName() const;
    void addFriend(User *);
    void removeFriend(User *);
    void post(std::string _text);
    void post(std::string _text, Media *_media);
    const std::list<Post *> getPosts() const;
    void viewFriendsPosts() const;
    void receiveMessage(Message *);
    virtual void sendMessage(User *, Message *);
    void viewReceivedMessages() const;

protected:
    unsigned long id;
    std::string name;
    std::list<unsigned long> friends;
    std::list<Post *> posts;
    std::list<Message *> receivedMessages;
    USocial *social_network;

    User();
    ~User();

private:
    bool isFriendOf(User *_user) const;
    std::string addUserNameToString(const std::string &_origin, const std::string &_text_type);
};

#endif // _USER_H_