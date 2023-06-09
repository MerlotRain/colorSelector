cmake_minimum_required(VERSION 3.0..3.24)
project(colorSelector)

set(COLORSELECT_VERSION_MAJOR 1)
set(COLORSELECT_VERSION_MINOR 0)
set(COLORSELECT_VERSION_PATCH 1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4") # level 4 warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP") # multi-processor compilation
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # all warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra") # extra warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-pragmas") # ignore MSVC and Clang pragmas
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-maybe-uninitialized") # GCC diagnostic with lots of false positives
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything") # all warnings
    # blacklist warnings that are not relevant
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++98-compat") # ignore warnings about C++98 compatibility
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++98-compat-pedantic") # ignore pedantic warnings about C++98 compatibility
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-padded") # ignore padding warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-documentation-unknown-command") # ignore unknown commands in Javadoc-style comments
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-pragmas") # ignore Windows and GCC pragmas
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-warning-option") # ignore Windows and GCC pragmas
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-newline-eof") # no longer an issue with post-c++11 standards which mandate include add a newline if neccesary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-covered-switch-default") # default is often added to switches for completeness or to cover future alternatives
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-exit-time-destructors") # this is just a warning to notify that the destructor will run during exit
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-missing-braces") # Wmissing-field-initializers has less false positives
endif ()

find_package(Qt5 COMPONENTS Core Widgets)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/core/gradient.h
        src/core/scheme.h
        src/core/gradient/blockgradient.cpp
        src/core/gradient/lineargradient.cpp
        src/core/gradient/linearhsvgradient.cpp
        src/core/gradient/randomgradient.cpp
        src/core/scheme/continuouscolorscheme.cpp
        src/core/scheme/discretecolorscheme.cpp
        src/core/scheme/multicolorscheme.cpp
        src/core/scheme/randomcolorscheme.cpp
        src/UI/model/hsvcomboxdelegate.h
        src/UI/model/hsvcomboxdelegate.cpp
        src/UI/model/hsvcomboxmodel.h
        src/UI/model/hsvcomboxmodel.cpp
        src/UI/colorselectcombobox.h
        src/UI/colorselectcombobox.cpp
        src/UI/coloreditor/coloreditor.h
        src/UI/coloreditor/coloreditor.cpp
        src/UI/coloreditor/colorslider.h
        src/UI/coloreditor/colorslider.cpp
        src/UI/coloreditor/colorslidergroove.h
        src/UI/colormosaicbar.h
        src/UI/colormosaicbar.cpp
        src/UI/colorblockwidget.h
        src/UI/colorblockwidget.cpp
        src/UI/colorrampwidget.h
        src/UI/colorrampwidget.cpp
        src/UI/colorschemebar.h
        src/UI/colorschemebar.cpp
        )

set(COLORSELECTOR_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${COLORSELECTOR_INCLUDE_PATH})

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        Qt::Core
        Qt::Widgets)