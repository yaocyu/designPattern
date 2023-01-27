//
// Created by chaoyu on 2023/1/26.
//

#ifndef MVC_PIECHARTVIEW_H
#define MVC_PIECHARTVIEW_H

#include "ViewInterface.h"
#include "../model/Model.h"
#include "../controller/Controller.h"

class PieChartView :public ViewInterface{
public:
    PieChartView(Model* model)
    {
        this->m_model = model;
        model->registerView(this);
        m_controller = new Controller(model,this);
    }

    void update()
    {
        std::cout<< "PieChartView display string:"  << m_model->getData()  << std::endl;
    }
//    void userInput(std::string data)
//    {
//        m_controller->setValues(data);
//    }
private:
    Model *m_model;
    Callable* m_controller;
};

#endif //MVC_PIECHARTVIEW_H
