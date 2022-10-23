#ifndef _MEDIA_H_
#define _MEDIA_H_

#include <iostream>
#include <string>

class Media
{
protected:
    std::string media_type;

    // we don't want anyone to instantiate a media that is not explicitly specified
    Media(){};

public:
    // functions
    void display() const;
};

#endif // _MEDIA_H_