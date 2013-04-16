cmake_minimum_required(VERSION 2.8)

#set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "-g -Wall")

# get boost
set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS
                system
                thread
                python
             REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

# get python
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
link_directories(${PYTHON_LIBRARIES})

add_library(predicates predicates.c)

add_library(test_l SHARED test_l.cpp)
SET_TARGET_PROPERTIES(test_l PROPERTIES PREFIX "")
SET_TARGET_PROPERTIES(test_l PROPERTIES SUFFIX ".so")
target_link_libraries(test_l
    ${Boost_LIBRARIES}
    ${PYTHON_LIBRARIES}
    predicates
)

add_executable(test test.c)
target_link_libraries(test predicates)
