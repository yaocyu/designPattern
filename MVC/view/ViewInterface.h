//
// Created by chaoyu on 2023/1/26.
//

#ifndef MVC_VIEWINTERFACE_H
#define MVC_VIEWINTERFACE_H
#include <iostream>
#include <string>


class ViewInterface {
public:
    virtual void update()  = 0;
//    virtual void userInput(std::string data) = 0;
};


#endif //MVC_VIEWINTERFACE_H
