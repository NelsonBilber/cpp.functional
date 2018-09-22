project(functional)
cmake_minimum_required(VERSION 2.8)
include(CheckCXXCompilerFlag)

# Check for standard to use

# And so on and on...
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
message (STATUS "c++14")


#enable threads
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)
if(CMAKE_USE_PTHREADS_INIT)
    set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-pthread")
else()
    message (STATUS "Cannot enable multithreading.")
endif()

#include all headers files from current dir
file(GLOB HEADER_FILES   "*.h")

#include all cpp files from current dir
aux_source_directory(. SRC_LIST)

#set up executable
add_executable(${PROJECT_NAME} ${SRC_LIST} ${HEADER_FILES})
target_link_libraries( ${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} )
