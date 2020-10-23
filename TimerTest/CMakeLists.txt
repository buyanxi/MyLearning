# Define project name
project(TimerTest)

# Enable C++11
cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )

message(${PROJECT_SOURCE_DIR})

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

# Declare the executable target built from your sources
set (SOURCES
     ./main.cpp
     ./src/Timer.cpp
)

add_executable (TimerTest ${SOURCES})

# Link your application with other libraries
target_link_libraries(TimerTest 
      pthread dl
)
