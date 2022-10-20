#ifndef _POST_H_
#define _POST_H_

#include <iostream>
#include <string>

#include "Media.h"

class Post
{
private:
    std::string posting_time;
    std::string text;
    Media *media;

    // functions
    const std::string getCurrentTime();

public:
    // constructors
    Post(const std::string _text);
    Post(const std::string _text, Media *_media);

    // destructor
    ~Post();

    // functions
    const std::string &getText() const;
    const Media *getMedia() const;
    void display() const;
};

#endif // _POST_H_