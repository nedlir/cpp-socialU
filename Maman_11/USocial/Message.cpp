#include "Message.h"

Message::Message(const std::string _text)
{

    sent_time = getCurrentTime();

    if (_text.empty())
        text = "Empty Message";
    else
        text = _text;
}

Message::~Message()
{
}

void Message::display() const
{
    std::cout << "Time sent: " << sent_time;

    std::cout << "Message: " << text << std::endl;
}

const std::string Message::getCurrentTime()
{
    time_t current_time = time(0);
    return ctime(&current_time);
}