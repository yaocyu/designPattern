#include <iostream>
#include "controller/Controller.h"
#include "view/PieChartView.h"
#include "view/TableView.h"

int main() {

    Model* m = new Model();
    TableView* tableView = new TableView(m);
    PieChartView* pieChartView = new PieChartView(m);

    tableView->userInput("clicked ");
    m->notifyView();
//
//    Controller c(m,pieChartView);
//
//    m.set_data("Hello, World!");
    return 0;
}
