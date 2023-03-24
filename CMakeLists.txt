cmake_minimum_required(VERSION 3.0..3.24)
project(colorSelector)

set(COLORSELECT_VERSION_MAJOR 1)
set(COLORSELECT_VERSION_MINOR 0)
set(COLORSELECT_VERSION_PATCH 1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4") # level 4 warnings
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP") # multi-processor compilation
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall") # all warnings
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra") # extra warnings
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-pragmas") # ignore MSVC and Clang pragmas
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-maybe-uninitialized") # GCC diagnostic with lots of false positives
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
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
endif()

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/utiltiy/blockgradient.cpp
    src/utiltiy/color.cpp
    src/utiltiy/continuouscolorscheme.cpp
    src/utiltiy/discretecolorscheme.cpp
    src/utiltiy/lineargradient.cpp
    src/utiltiy/linearhsvgradient.cpp
    src/utiltiy/multicolorscheme.cpp
    src/utiltiy/randomcolorscheme.cpp
    src/utiltiy/randomgradient.cpp
    include/utiltiy/color.h
    include/utiltiy/gradient.h
    include/utiltiy/scheme.h
    )

set(COLORSELECTOR_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${COLORSELECTOR_INCLUDE_PATH})