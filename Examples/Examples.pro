TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Associative_Containers/map.cpp \
    Associative_Containers/set.cpp \
    Associative_Containers/unordered_containers.cpp \
    Container_Adaptors/priority_queue.cpp \
    Container_Adaptors/queue.cpp \
    Container_Adaptors/stack.cpp \
    Sequence_Containers/array.cpp \
    Sequence_Containers/deque.cpp

HEADERS += \
    Associative_Containers/map.h \
    Associative_Containers/unordered_containers.h
