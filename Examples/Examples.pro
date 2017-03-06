TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    \ Associative_Containers\map.cpp \
    \ Associative_Containers\set.cpp \
    Sequence_Containers/array.cpp \
    Sequence_Containers/deque.cpp \
    Associative_Containers/unordered_containers.cpp \
    Container_Adaptors/stack.cpp \
    Container_Adaptors/queue.cpp \
    Container_Adaptors/priority_queue.cpp
