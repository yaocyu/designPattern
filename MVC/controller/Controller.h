//
// Created by chaoyu on 2023/1/26.
//

#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H


#include "../model/Model.h"
#include "../view/ViewInterface.h"

#include "Callable.h"

class Controller:public Callable
{
public:
    Controller(Model* model,ViewInterface* view)
    {
        m_model = model;
        m_view= view;
    }

    void setValues(std::string data)
    {
        if (m_model != nullptr)
            m_model->processData(data);
        else
            printf("m_model nullptr\n");
    }
private:
    Model* m_model = nullptr;
    ViewInterface*  m_view = nullptr;
};

#endif //MVC_CONTROLLER_H
