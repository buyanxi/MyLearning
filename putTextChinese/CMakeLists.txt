# Define project name
project(putTextChinese)

# Enable C++11
cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/ )

# Find OpenCV
message("***************Find OpenCV")
find_package(OpenCV REQUIRED)
message("\n")

include_directories(
        ${OpenCV_INCLUDE_DIRS}
)

# Declare the executable target built from your sources
set (SOURCES
        ./main.cpp
)
add_executable (putTextChinese ${SOURCES})

# Link your application with other libraries
target_link_libraries(putTextChinese 
      ${OpenCV_LIBS}
      pthread dl
)
