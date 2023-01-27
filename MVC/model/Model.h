//
// Created by chaoyu on 2023/1/26.
//

#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include <list>
#include "../controller/Callable.h"
#include "../view/ViewInterface.h"

class Model {
public:
    /**
      * @brief  
      * @note   None
      * @param  None
      * @retval None
    */
    std::string getData()const
    {
        return this->m_data;
    }

    void notifyView()
    {

        std::list<ViewInterface*>::iterator listIterator =m_viewList.begin();

        while (listIterator != m_viewList.end() ){
                (*listIterator)->update();
                listIterator++;
         }
    }

    /**
      * @brief
      * @note   None
      * @param  None
      * @retval None
    */
    void registerView(ViewInterface* view)
    {
        m_viewList.push_back(view);
    }

    void deleteView(ViewInterface* view)
    {
        m_viewList.remove(view);
    }

    void processData(std::string data)
    {
        m_data = data+"processed";
    }
private:
    std::string m_data;
    std::list<ViewInterface*> m_viewList;
};


#endif //MVC_MODEL_H
