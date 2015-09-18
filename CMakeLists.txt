cmake_minimum_required(VERSION 2.8)

project(XPlat)

add_definitions(-DUNICODE)

set(_BASE_PATH_ ${CMAKE_CURRENT_LIST_DIR})
set(_SRC_PATH_ ${_BASE_PATH_}/src)


file(GLOB_RECURSE HEADER_FILES
    ${_SRC_PATH_}/include/*.h
    ${_SRC_PATH_}/code/net/socket/*.h
    ${_SRC_PATH_}/code/net/reactor/*.h
    ${_SRC_PATH_}/code/oss/process/*.h
    ${_SRC_PATH_}/code/oss/thread/*.h
    ${_SRC_PATH_}/code/schedual/*.h
    ${_SRC_PATH_}/*.h
)
file(GLOB_RECURSE SRC_FILES
    ${_SRC_PATH_}/code/net/socket/*.cpp
    ${_SRC_PATH_}/code/net/reactor/*.cpp
    ${_SRC_PATH_}/code/oss/process/*.cpp
    ${_SRC_PATH_}/code/oss/thread/*.cpp
    ${_SRC_PATH_}/code/schedual/*.cpp
    ${_SRC_PATH_}/*.cpp
)

include_directories(${_BASE_PATH_}/src/include)
include_directories(${_BASE_PATH_}/src/code/net/socket)


############################################################################################
MESSAGE(STATUS "--------------------------------------") 
MESSAGE(STATUS "    PROJECT:         ${CMAKE_PROJECT_NAME}") 
MESSAGE(STATUS "        BASE_PATH:   ${_BASE_PATH_}" )
MESSAGE(STATUS "        SRC_PATH:    ${_SRC_PATH_}" )
MESSAGE(STATUS "        LIB:         ${PROJECT_NAME}" )
MESSAGE(STATUS "        DIR:         ${CMAKE_CURRENT_LIST_DIR}" )
MESSAGE(STATUS "        BIN:         ${CMAKE_CURRENT_BINARY_DIR}" )
MESSAGE(STATUS "        SRC:         ${SRC_FILES}" )
############################################################################################


add_library(${PROJECT_NAME} STATIC ${SRC_FILES} ${HEADER_FILES})
set(LIBRARY_OUTPUT_PATH ${_BASE_PATH_}/target/lib/)

