# MVC
A implementation of the MVC pattern 
![MVC pattern diagram](image/mvc.bmp)
### MVC架构模式确定了数据和数据加工在模型中、数据的显示在视图、对用户输入的解释在控制器。视图和控制器共同组成了用户接口。
>三个组件的任务如下：
+ **模型**包括核心功能，它封装了系统的数据和对数据的加工。
+ **视图**把数据展示给用户，它含有模型要展示的数据。
+ **控制器**负责接收用户的输入，并负责对输入的内容做解释。

```mermaid
classDiagram
    class Model
    ViewInterface <|-- PieChartView
    ViewInterface <|-- TableView
    Callable  <|-- Controller
    Model --* PieChartView
    Callable --* PieChartView
    Model --* TableView
    Callable --* TableView
    ViewInterface --* Model
    ViewInterface --* Controller
    Model --* Controller

    class ViewInterface{
        <<interface>>
        +update()
    }
    class Callable{
        <<interface>>
        +setValues(std::string data)
    }
    class Controller{
        -Model* m_model 
        -ViewInterface*  m_view 
        +setValues(std::string data)
    }
    class Model{
        +registerView(ViewInterface* view)
        +notifyView()
        +processData(std::string data)
        -std::string m_data;
        -std::list<ViewInterface*> m_viewList;
    }
    class TableView {
        +void update()
        +void userInput(std::string data)

        -Model *m_model;
        -Callable* m_controller;
    }
    class PieChartView {
        +void update()

        -Model *m_model;
        -Callable* m_controller;
    }
```
```mermaid
sequenceDiagram
    participant Controller
    participant Model
    participant TableView
    participant PieChartView
    TableView->>+Model: registerView
    Model-->>-TableView: registerView
    PieChartView->>+Model: registerView
    Model-->>-PieChartView: registerView
    
    TableView->>+Controller: userInput
    Controller->>+Model: setValues
    Model->>Model:processData
    Model-->>-Controller: setValues
    Controller-->>-TableView: userInput

loop notifyView
    Model->>+Model:更新视图

    Model->>+TableView: update
    TableView->>+Model: getData
    Model-->>-TableView: getData
    TableView-->>-Model: update

    Model->>+PieChartView: update
    PieChartView->>+Model: getData
    Model-->>-PieChartView: getData
    PieChartView-->>-Model: update

    Model-->>-Model:更新视图
end
```

