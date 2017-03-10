TEMPLATE = app
CONFIG += console c++14
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
    Sequence_Containers/deque.cpp \
    Performance/performance.cpp

HEADERS += \
    Associative_Containers/map.h \
    Associative_Containers/unordered_containers.h \
    Performance/performance.h \
    Sequence_Containers/array.h \
    Sequence_Containers/deque.h \
    Container_Adaptors/priority_queue.h \
    Container_Adaptors/stack.h \
    Container_Adaptors/queue.h \
    Associative_Containers/set.h
