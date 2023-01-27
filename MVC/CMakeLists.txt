cmake_minimum_required(VERSION 3.21)
project(MVC)

set(CMAKE_CXX_STANDARD 11)

add_executable(MVC main.cpp model/Model.cpp model/Model.h controller/Controller.cpp controller/Controller.h controller/Callable.h view/ViewInterface.h view/TableView.cpp view/TableView.h view/PieChartView.cpp view/PieChartView.h)
