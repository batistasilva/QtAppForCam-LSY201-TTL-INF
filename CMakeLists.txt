cmake_minimum_required(VERSION 3.16)

project(QtAppForCam-LSY201-TTL-INF LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS SerialPort Core Widgets)
find_package(OpenCV REQUIRED)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(QtAppForCam-LSY201-TTL-INF
   ${PROJECT_SOURCES}
   settings/serialportsettings.cpp
   settings/serialportsettings.h
   settings/serialportsettings.ui
   serialport/mserialport.ui
   serialport/receiverthread.cpp
   serialport/receiverthread.h
   serialport/senderthread.cpp
   serialport/senderthread.h
   uvideo/globals.cpp
   uvideo/globals.h
   uvideo/showmsg.cpp
   uvideo/showmsg.h
   uvideo/videoutil.cpp
   uvideo/videoutil.h
   settings/mngsportsetting.h settings/mngsportsetting.cpp
)
target_link_libraries(QtAppForCam-LSY201-TTL-INF
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt6::SerialPort
)
target_link_libraries(QtAppForCam-LSY201-TTL-INF Qt6::Core ${OpenCV_LIBS})

include(GNUInstallDirs)
install(TARGETS QtAppForCam-LSY201-TTL-INF
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
