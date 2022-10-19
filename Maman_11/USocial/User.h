#ifndef _USER_H_
#define _USER_H_

#include <list>
#include <vector>
#include "USocial.h"

class User
{
    // Friend classes:
    friend class USocial;

protected:
    // Variables
    USocial *network;
    unsigned long id;
    std::string username;
    // list<Post *> posts;
    // list<Message *> messages;

    // Constructor
    User();

    // Destructor
    ~User();

public:
    unsigned long getId() const;
    const std::string &getName() const;
    void addFriend(const User *user);
    void removeFriend(const User *user);
    // void post(const std::string &post_text);
    // void post(const std::string &post_text, const Media *media = nullptr);
    // const std::vector<const Post *> &getPosts() const;
    void viewFriendsPosts() const;
    // void receiveMessage(const Message *message);
    // virtual void sendMessage(User *user, const Message *message);
    // void viewReceivedMessages() const;
}

#endif // _USER_H_