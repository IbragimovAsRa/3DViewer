

cmake_minimum_required(VERSION 3.14)
project(3dViewer LANGUAGES C CXX)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(../)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
#find_package(Qt6 REQUIRED COMPONENTS OpenGL)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(3dViewer
        3dViewer/main.cpp
        3dViewer/mainwindow.h 3dViewer/mainwindow.cpp 3dViewer/mainwindow.ui
        3dViewer/GLViewer.h 3dViewer/GLViewer.cpp
        Parser/parser.h Parser/parser.c
        Transformer/transformer.c Transformer/transformer.h
)

#add_library(Parser Parser/parser.c  Parser/parser.h)
#add_subdirectory(Parser)


target_link_libraries(3dViewer PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    #Qt${QT_VERSION_MAJOR}::OpenGL
    Qt6::OpenGLWidgets
#    Parser
)

TARGET_LINK_LIBRARIES(3dViewer ${QT_LIBRARIES})

include(GNUInstallDirs)
#Надо переделать на один файл glviewer.h
include_directories(3dViewer)

install(TARGETS 3dViewer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR}
)
