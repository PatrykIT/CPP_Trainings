#include "shared_ptr.h"
#include <iostream>
#include <memory>

void SHARED_MEELOGIC::Start()
{

}


void SHARED_MEELOGIC::Shared_Ptr_Contructors_Custom_Class_1()
{
    std::shared_ptr<Objects> object_ptr_one = std::make_shared<Objects>();
    std::shared_ptr<Objects> object_ptr_two (object_ptr_one);

}

SHARED_MEELOGIC::Objects::Objects() { std::cout << "Constructor called.\n"; }
SHARED_MEELOGIC::Objects::Objects(int nr) { x = nr; std::cout << "Constructor with parameter called.\n"; }
SHARED_MEELOGIC::Objects::~Objects() { std::cout << "Destructor called.\n"; }
SHARED_MEELOGIC::Objects::Objects(const Objects &other) { std::cout << "Copy constructor called.\n"; std::ignore = other; }
SHARED_MEELOGIC::Objects& SHARED_MEELOGIC::Objects::operator=(const Objects &other) { std::cout << "Assignment constructor called.\n"; std::ignore = other; return *this;}
SHARED_MEELOGIC::Objects::Objects(Objects &&other) { std::cout << "Move constructor called.\n"; std::ignore = other; }
SHARED_MEELOGIC::Objects& SHARED_MEELOGIC::Objects::operator=(Objects &&other) { std::cout << "Move assignment constructor called.\n"; std::ignore = other; return *this; }
