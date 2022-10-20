#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <string>

class Message
{
private:
    std::string text;

public:
    // constructor
    Message(const std::string _text);

    // destructor
    ~Message();

    // functions
    void display() const;
};

#endif // _MESSAGE_H_