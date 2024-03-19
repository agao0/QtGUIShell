cmake_minimum_required(VERSION 3.14)

project(Vrex_Console_GUI LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Vrex_Console_GUI
  main.cpp
  consolereader.h consolereader.cpp
  inputmap.h inputmap.cpp
  commandexecutor.h commandexecutor.cpp
  streamworker.h streamworker.cpp
  gui_start.h gui_start.cpp

)
target_link_libraries(Vrex_Console_GUI Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Vrex_Console_GUI
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
