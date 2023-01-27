cmake_minimum_required(VERSION 3.16)

project(GsiApp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Charts)
qt_standard_project_setup()

add_executable(GsiApp
    main.cpp CSVSource.h DataProvider.h MainModel.h MainView.h MainViewController.h RollingAverage.h
)

target_link_libraries(GsiApp PRIVATE     
    Qt::Core
    Qt::Gui
    Qt::Widgets
    Qt::Charts)

#set_target_properties(GsiApp PROPERTIES
#    MACOSX_BUNDLE ON
#)