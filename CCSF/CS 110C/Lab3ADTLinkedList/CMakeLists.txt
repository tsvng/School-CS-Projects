cmake_minimum_required(VERSION 3.6)
project(Lab3ADTLinkedList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Lab3ADTLinkedList/linkedlist.cpp
    Lab3ADTLinkedList/LinkedList.h
    Lab3ADTLinkedList/LinkedListEqualsClient.cpp
    Lab3ADTLinkedList/LinkedListReplaceClient.cpp
    Lab3ADTLinkedList/ListException.h
    Lab3ADTLinkedList/ListInterface.h
    Lab3ADTLinkedList/ListPositionOutOfRangeException.h
    Lab3ADTLinkedList/Node.cpp
    Lab3ADTLinkedList/Node.h)

add_executable(Lab3ADTLinkedList ${SOURCE_FILES})