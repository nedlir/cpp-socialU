#ifndef _BUSINESS_USER_H_
#define _BUSINESS_USER_H_

#include "User.h"

class BusinessUser : public User
{
    friend class USocial;

    virtual void sendMessage(User *_user, Message *_message);
};

#endif // _BUSINESS_USER_H_