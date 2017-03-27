#include "unique_ptr.h"
#include <memory>
#include <iostream>

void UNIQUE_MEELOGIC::Start()
{
    Unique_Ptr_Interface();
}

void UNIQUE_MEELOGIC::Unique_Ptr_Interface()
{
    std::unique_ptr<int> unique_number_0 = std::make_unique<int> (20);
    std::unique_ptr<int> unique_number_1 = std::make_unique<int> (5);
    std::unique_ptr<int> unique_number_2 = std::make_unique<int> (5);


    std::cout << *unique_number_0 << "\n";
    std::cout << *unique_number_1 << "\n";
    std::cout << *unique_number_2 << "\n";


    /* GET */
    int *raw_pointer = unique_number_0.get(); //Unique_ptr will stil delete the object at the end of scop (unlike .release() method)
    std::cout << "raw_pointer after calling .get(): " << *raw_pointer << "\n";

    /* RELEASE */
    int *raw_pointer_2 = unique_number_1.release();
    std::cout << "raw_pointer_2 after calling .release(): " << *raw_pointer_2 << "\n";
    delete raw_pointer_2; //Need to manually delete it, as unique_ptr no longer holds ownership!

    /* RESET */
    unique_number_2.reset(new int (100)); //Deletes the previous object, and inserts a new one.
    std::cout << *unique_number_2 << "\n";

    /* SWAP */
    std::cout << "Before swapping: " << *unique_number_0 << " - " << *unique_number_2 << "\n";
    unique_number_0.swap(unique_number_2); //Swaps contents of both pointers.
    std::cout << "After swapping: " <<  *unique_number_0 << " - " << *unique_number_2 << "\n";
}

void UNIQUE_MEELOGIC::Unique_Ptr_Contructors()
{
    /* First construct option */
    std::unique_ptr<int> unique_number_0 (new int (20));

    /* Second construct option */
    int *number_ptr = new int (10);
    std::unique_ptr<int> unique_number_1 (std::move(number_ptr)); //After moving number_ptr, the raw pointer might be null'ed and cannot be accessed!

    /* Third construct option */
    std::unique_ptr<int> unique_number_2 = std::make_unique<int> (5);


    std::cout << *unique_number_0 << "\n";
    std::cout << *unique_number_1 << "\n";
    std::cout << *unique_number_2 << "\n";
}


UNIQUE_MEELOGIC::Objects::Objects() { std::cout << "Constructor called.\n"; }
UNIQUE_MEELOGIC::Objects::~Objects() { std::cout << "Destructor called.\n"; }
UNIQUE_MEELOGIC::Objects::Objects(const Objects &other) { std::cout << "Copy constructor called.\n"; std::ignore = other; }
UNIQUE_MEELOGIC::Objects& UNIQUE_MEELOGIC::Objects::operator=(const Objects &other) { std::cout << "Assignment constructor called.\n"; std::ignore = other; return *this;}
UNIQUE_MEELOGIC::Objects::Objects(Objects &&other) { std::cout << "Move constructor called.\n"; std::ignore = other; }
UNIQUE_MEELOGIC::Objects& UNIQUE_MEELOGIC::Objects::operator=(Objects &&other) { std::cout << "Move assignment called.\n"; std::ignore = other; return *this; }
