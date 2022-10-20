#include <iostream>
#include "Media.h"

// display the media on the screen
void Media::display() const
{
    std::cout << "Media: ";

    if (media_type == "Video" || media_type == "Audio")
        std::cout << media_type << " is playing" << std::endl;
    else if (media_type == "Photo")
        std::cout << media_type << " is displayed" << std::endl;
    else
        std::cout << "Undefined media type" << std::endl;
}