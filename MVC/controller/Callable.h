//
// Created by chaoyu on 2023/1/26.
//

#ifndef MVC_CALLABLE_H
#define MVC_CALLABLE_H

#include <string>

class Callable {
public:
    virtual ~Callable(){}
    virtual void setValues(std::string data)=0;
};


#endif //MVC_CALLABLE_H
