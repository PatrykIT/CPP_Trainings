#include "shared_ptr.h"
#include <iostream>
#include <memory>


/* Add example with raw pointers. int *object = new object; int *raw1 = object; int *raw2 = object; delete object;
 * And then show shared_ptr implementation*/
void SHARED_MEELOGIC::Start()
{
    //Shared_Ptr_Contructors_Custom_Class_1();
    Shared_Ptr_Unique();
}


/* TODO: See what happens when you try to move shared ptr to another shared ptr. */

void SHARED_MEELOGIC::Shared_Ptr_Contructors_Custom_Class_1()
{
    std::shared_ptr<Objects> object_ptr_one = std::make_shared<Objects>(5);
    std::shared_ptr<Objects> object_ptr_two (object_ptr_one);

    long shared_pointers_in_use = object_ptr_one.use_count();
    std::cout << "Shared pointers in use: " << shared_pointers_in_use << "\n";

}


void SHARED_MEELOGIC::Shared_Ptr_Unique()
{
    std::shared_ptr<Objects> object_ptr_one = std::make_shared<Objects>(5);
    std::shared_ptr<Objects> object_ptr_two (object_ptr_one);

    std::cout << "Is only one pointer pointing to object? : " << std::boolalpha << object_ptr_one.unique() << "\n";
    object_ptr_two.reset(); //Question to the class: Will this delete original object?
    std::cout << "After reseting one shared_ptr, is only one pointer pointing to object? : " << std::boolalpha << object_ptr_one.unique() << "\n";
}


SHARED_MEELOGIC::Objects::Objects() { std::cout << "Constructor called.\n"; }
SHARED_MEELOGIC::Objects::Objects(int nr) { x = nr; std::cout << "Constructor with parameter called.\n"; }
SHARED_MEELOGIC::Objects::~Objects() { std::cout << "Destructor called.\n"; }

SHARED_MEELOGIC::Objects::Objects(const Objects &other) { std::cout << "Copy constructor called.\n"; std::ignore = other; }
SHARED_MEELOGIC::Objects& SHARED_MEELOGIC::Objects::operator=(const Objects &other)
{ std::cout << "Assignment constructor called.\n"; std::ignore = other; return *this;}

SHARED_MEELOGIC::Objects::Objects(Objects &&other) { std::cout << "Move constructor called.\n"; std::ignore = other; }
SHARED_MEELOGIC::Objects& SHARED_MEELOGIC::Objects::operator=(Objects &&other)
{ std::cout << "Move assignment constructor called.\n"; std::ignore = other; return *this; }
