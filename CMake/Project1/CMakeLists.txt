cmake_minimum_required(VERSION 3.16)

project(TestMath VERSION 1.0)

add_executable(test_math test_math.cxx)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

configure_file(Config.h.in Config.h)
#include_directories(../include)
#target_include_directories(test PUBLIC include)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#target_include_directories(test PUBLIC 
#                        "${PROJECT_BINARY_DIR}"
#                        "${PROJECT_SOURCE_DIR}/Utility"
#)   

option (WITH_UTIL_ON "Use Utility" ON)
if (WITH_UTIL_ON)
    add_subdirectory(Utility)
    list(APPEND EXTRA_LIBS Utility)
    list(APPEND EXTRA_INCLUDE "${PROJECT_SOURCE_DIR}/Utility")
    MESSAGE(STATUS "UTIL ON")
    add_definitions(-DUTIL_ON)
endif()



target_link_libraries(test_math PUBLIC ${EXTRA_LIBS})
target_include_directories(test_math PUBLIC 
                        "${PROJECT_BINARY_DIR}"
                        "${EXTRA_INCLUDE}"
)

enable_testing()

add_test(NAME Runs COMMAND test_math 23)

add_test(NAME Usage COMMAND test_math)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
)

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# do a bunch of result based tests
do_test(test_math 4 "4 is 2")
#do_test(test_math 9 "9 is 3")
#do_test(test_math 5 "5 is 2.236")
#do_test(test_math 7 "7 is 2.645")
#do_test(test_math 25 "25 is 5")
#do_test(test_math -25 "-25 is (-nan|nan|0)")
#do_test(test_math 0.0001 "0.0001 is 0.01")