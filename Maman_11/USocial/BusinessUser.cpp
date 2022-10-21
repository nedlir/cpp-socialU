#include "BusinessUser.h"

void BusinessUser::sendMessage(User *_user, Message *_message)
{
    _user->receiveMessage(_message);
}