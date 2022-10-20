#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <iostream>
#include <string>

class Message
{
private:
    std::string sent_time;
    std::string text;

    // functions
    const std::string getCurrentTime();

public:
    // constructor
    Message(const std::string _text);

    // destructor
    ~Message();

    // functions
    void display() const;
};

#endif // _MESSAGE_H_