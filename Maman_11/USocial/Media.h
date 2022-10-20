#ifndef _MEDIA_H_
#define _MEDIA_H_

#include <iostream>

class Media
{
protected:
    // we don't want anyone to instantiate a media that is not explicitly specified
    Media(){};
    ~Media(){};
    std::string media_type;

public:
    // functions
    virtual void display() const;
};

#endif // _MEDIA_H_