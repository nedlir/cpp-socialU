#include <iostream>

#include "Message.h"

Message::Message(const std::string _text)
{
    text = _text;
}

inline void Message::display() const
{
    std::cout << "Message: " << text << std::endl;
}