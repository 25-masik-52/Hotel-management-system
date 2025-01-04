cmake_minimum_required(VERSION 3.20)

project(HotelManagementSystemServer LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Sql Network)

file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/configuration.ini
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(HotelManagementSystemServer
    ${HEADERS}
    ${SOURCES}
)
target_link_libraries(HotelManagementSystemServer
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::Network
)

include(GNUInstallDirs)
install(TARGETS HotelManagementSystemServer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
