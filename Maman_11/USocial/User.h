#ifndef _USER_H_
#define _USER_H_

#include "Post.h"
#include "Message.h"
#include <string>
#include <list>
#include "USocial.h"

class User
{
    friend class USocial;

protected:
    unsigned long id;
    std::string name;
    std::list<unsigned long> friends;
    std::list<Post *> posts;
    std::list<Message *> receivedMessages;
    USocial *us;

    User();
    ~User();

public:
    unsigned long getId();
    const std::string &getName() const;
    void addFriend(User *_user);
    void removeFriend(User *_user);
    void post(std::string &_text);
    void post(std::string &_text, Media *_media);
    void viewFriendsPosts() const;
    void receiveMessage(Message *_message);
    virtual void sendMessage(User *_user, Message *_message);
    void viewReceivedMessages();
};

#endif // _USER_H_