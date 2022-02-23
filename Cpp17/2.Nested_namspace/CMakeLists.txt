cmake_minimum_required(VERSION 3.22)

project(nestednamespace VERSION 1.0)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
add_executable(nestednamespace nested_namespace.cxx)