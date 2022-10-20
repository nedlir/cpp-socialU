#include "USocial.h"
#include "User.h"
#include <exception>
#include <iostream>

#include "Media.h"
#include "Audio.h"
#include "Video.h"
#include "Photo.h"
#include "Post.h"
#include "Message.h"

int main()
{

    std::cout << "Media Objects: " << std::endl;

    Audio a1;
    Video a2;
    Photo a3;

    a1.display();
    a2.display();
    a3.display();

    std::cout << std::endl;
    std::cout << "Posts Objects: " << std::endl;

    Post p1("Hello World!");
    Post p2("Goodbye World!", &a2);
    Post p3("The fast fox jumped over the lazy dog!", &a3);

    p1.display();
    p2.display();
    p3.display();

    std::cout << "Messages Objects: " << std::endl;

    Message m1("Hello");
    m1.display();
    Message m2("Goodbye");
    m2.display();

    //     USocial us;
    //     User *u1 = us.registerUser("Liron");
    //     User *u2 = us.registerUser("Yahav");
    //     User *u3 = us.registerUser("Shachaf");
    //     User *u4 = us.registerUser("Tsur", true);
    //     User *u5 = us.registerUser("Elit");
    //     u1->post("Hello world!");
    //     u2->post("I'm having a great time here :)", new Audio());
    //     u3->post("This is awesome!", new Photo());
    //     u5->addFriend(u1);
    //     u5->addFriend(u2);
    //     u5->viewFriendsPosts(); // should see only u1, u2 s' posts
    //     u4->sendMessage(u5, new Message("Buy Falafel!"));
    //     u5->viewReceivedMessages();
    //     try
    //     {
    // u3->sendMessage(u5, new Message("All your base are belong to
    // us"));
    //     }
    //     catch (const std::exception &e)
    //     {
    //         std::cout << "error: " << e.what() << std::endl;
    //     }
    //     u5->viewReceivedMessages();
    //     u3->addFriend(u5);
    //     u3->sendMessage(u5, new Message("All your base are belong to us"));
    //     u5->viewReceivedMessages();
    return 0;
}