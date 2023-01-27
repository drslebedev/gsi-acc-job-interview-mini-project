#include <iostream>

#include <QApplication>
#include "MainViewController.h"


int main (int argc, char **argv)
{
    QApplication app(argc, argv);

    auto mainView = new MainView();
    MainViewController viewController;
    viewController.setView(mainView);
    
    QWidget* mainWindow = new QWidget;
    mainWindow->setLayout(mainView);
    mainWindow->resize(1000, 600);
    mainWindow->show();
    mainWindow->setWindowTitle("GSI");

    return app.exec();
}