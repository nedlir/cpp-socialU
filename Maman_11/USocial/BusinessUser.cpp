#include "BusinessUser.h"

void BusinessUser::sendMessage(User *_user, Message *_message)
{
    if (isFriendOf(_user))
        _user->receiveMessage(_message);
}