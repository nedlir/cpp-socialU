#include "Post.h"

Post::Post(const std::string _text)
{
    posting_time = getCurrentTime();
    text = _text;
    media = nullptr;
}

Post::Post(const std::string _text, Media *_media)
{
    posting_time = getCurrentTime();
    text = _text;
    media = _media;
}

Post::~Post()
{
    if (media != nullptr)
        delete media;
}

inline const std::string &Post::getText() const
{
    return text;
}

inline const Media *Post::getMedia() const
{
    return media;
}

void Post::display() const
{

    std::cout << "Time Posted: " << posting_time;

    std::cout << "Text: " << text << std::endl;

    if (media != nullptr)
        media->display();
}

const std::string Post::getCurrentTime()
{
    time_t current_time = time(0);
    return ctime(&current_time);
}