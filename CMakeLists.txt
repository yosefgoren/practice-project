cmake_minimum_required(VERSION 3.0.0)
project(project_mayham VERSION 0.1.0)

include(CTest)
enable_testing()

set(MTM_FLAGS_DEBUG "-std=c++11 -Wall -Werror -pedantic-errors")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")
set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

set(PROJECT_SOURCE_DIR "/source")
set(VEHICLES_SOURCE_DIR "${PROJECT_SOURCE_DIR}/Vehicle_Types_Source")
set(PROJECT_INCLUDE_DIR "/include")
set(VEHICLES_INCLUDE_DIR "${PROJECT_INCLUDE_DIR}/Vehicle_Types_Include")

include_directories(${PROJECT_INCLUDE_DIR} ${VEHICLES_INCLUDE_DIR})

#set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SRC
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${VEHICLES_SOURCE_DIR}/*.cpp"
)

add_executable(project_mayham main_test_terminal.cpp source/Time.cpp ${SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
