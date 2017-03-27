#include "unique_ptr.h"
#include <memory>
#include <iostream>

void UNIQUE_MEELOGIC::Start()
{
    //Unique_Ptr_Interface();
    //Unique_Ptr_Contructors_Custom_Class_1();
    //Unique_Ptr_Contructors_Custom_Class_2();
    //Unique_Ptr_Contructors_Custom_Class_3();
    Unique_Ptr_Contructors_Moving();
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
    std::unique_ptr<int> unique_number_1 (number_ptr);

    /* Third construct option */
    std::unique_ptr<int> unique_number_2 = std::make_unique<int> (5);


    std::cout << *unique_number_0 << "\n";
    std::cout << *unique_number_1 << "\n";
    std::cout << *unique_number_2 << "\n";
}



void UNIQUE_MEELOGIC::Unique_Ptr_Contructors_Custom_Class_1()
{
    std::unique_ptr<Objects> object_one (new Objects);
    std::unique_ptr<Objects> object_two (new Objects(7));
}


void UNIQUE_MEELOGIC::Unique_Ptr_Contructors_Custom_Class_2()
{
    Objects *object = new Objects;
    std::unique_ptr<Objects> ptr_to_object (object);
}


void UNIQUE_MEELOGIC::Unique_Ptr_Contructors_Custom_Class_3()
{
    std::unique_ptr<Objects> object_one = std::make_unique<Objects>();
    std::unique_ptr<Objects> object_two = std::make_unique<Objects>(7);

    std::cout << object_one->x << "\n";
    std::cout << object_two->x << "\n";
}


void UNIQUE_MEELOGIC::Unique_Ptr_Contructors_Moving()
{
    Objects *object = new Objects(5);
    std::cout << object->x << "\n";

    std::unique_ptr<Objects> first_ptr_to_object (object);
    std::cout << first_ptr_to_object->x << "\n";

    //std::unique_ptr<Objects> second_ptr_to_object  = first_ptr_to_object; //Will not compile. Unique_ptr's are not copyable. They are only movable.
    std::unique_ptr<Objects> second_ptr_to_object (std::move(first_ptr_to_object));
    std::cout << second_ptr_to_object->x << "\n";

    //std::cout << first_ptr_to_object->x << "\n"; //Crashes!! Don't touch the pointer that was "moved from".
    if(first_ptr_to_object == nullptr)
        std::cout << "Unique_pointer is empty. Please do not dereference.\n";
    else
        std::cout << first_ptr_to_object->x << "\n";
}


UNIQUE_MEELOGIC::Objects::Objects() { std::cout << "Constructor called.\n"; }
UNIQUE_MEELOGIC::Objects::Objects(int nr) { x = nr; std::cout << "Constructor with parameter called.\n"; }
UNIQUE_MEELOGIC::Objects::~Objects() { std::cout << "Destructor called.\n"; }
UNIQUE_MEELOGIC::Objects::Objects(const Objects &other) { std::cout << "Copy constructor called.\n"; std::ignore = other; }
UNIQUE_MEELOGIC::Objects& UNIQUE_MEELOGIC::Objects::operator=(const Objects &other) { std::cout << "Assignment constructor called.\n"; std::ignore = other; return *this;}
UNIQUE_MEELOGIC::Objects::Objects(Objects &&other) { std::cout << "Move constructor called.\n"; std::ignore = other; }
UNIQUE_MEELOGIC::Objects& UNIQUE_MEELOGIC::Objects::operator=(Objects &&other) { std::cout << "Move assignment constructor called.\n"; std::ignore = other; return *this; }

















