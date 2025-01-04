cmake_minimum_required(VERSION 3.20)

project(HotelManagementSystemClient VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Svg Xml Network)

file(GLOB HELPERS_H helpers/*.h)
file(GLOB HELPERS_CPP helpers/*.cpp)

file(GLOB PAGES_H pages/definition/*.h)
file(GLOB PAGES_CPP pages/definition/*.cpp)
file(GLOB PAGES_UI pages/forms/*.ui)

file(GLOB WIDGETS_H widgets/*/*.h)
file(GLOB WIDGETS_CPP widgets/*/*.cpp)
file(GLOB WIDGETS_UI widgets/*/*.ui)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    resources.qrc
    
    ${HELPERS_H}
    ${HELPERS_CPP}
    
    ${PAGES_H}
    ${PAGES_CPP}
    ${PAGES_UI}
    
    ${WIDGETS_H}
    ${WIDGETS_CPP}
    ${WIDGETS_UI}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(HotelManagementSystemClient
	MANUAL_FINALIZATION
	${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET HotelManagementSystemClient APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
	add_library(HotelManagementSystemClient SHARED
	    ${PROJECT_SOURCES}
	)
    # Define properties for Android with Qt 5 after find_package() calls as:
    #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
else()
    add_executable(HotelManagementSystemClient
	${PROJECT_SOURCES}
    )
endif()
endif()

target_link_libraries(HotelManagementSystemClient PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Svg
    Qt${QT_VERSION_MAJOR}::Xml
    Qt${QT_VERSION_MAJOR}::Network
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.HotelManagementSystemClient)
endif()
set_target_properties(HotelManagementSystemClient PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS HotelManagementSystemClient
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(HotelManagementSystemClient)
endif()
