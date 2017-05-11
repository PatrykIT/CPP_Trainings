#include "shared_ptr.h"
#include <iostream>
#include <memory>
#include <vector>


void SHARED_MEELOGIC::Start()
{
    //Shared_Ptr_Contructors_Custom_Class_1();
    //Shared_Ptr_Unique();

    //Share_Ownership_Raw_Pointers();
    //Share_Ownership_Shared_Pointers();

    //Vector_Shared_Pointers();
    Vector_Shared_Pointers_Wrong();
}



void SHARED_MEELOGIC::Shared_Ptr_Contructors_Custom_Class_1()
{
    std::shared_ptr<Objects> object_ptr_one = std::make_shared<Objects>(5);
    std::shared_ptr<Objects> object_ptr_two (object_ptr_one);

    long shared_pointers_in_use = object_ptr_one.use_count();
    std::cout << "Shared pointers in use: " << shared_pointers_in_use << "\n";
}

void Finish_Tomorrow()
{
    /* Remember not to initialize multiple shared pointers like this!! */
    Objects *object = new Objects(5);
    std::shared_ptr<Objects> first_ptr = object;
    std::shared_ptr<Objects> second_ptr = object;

}


void SHARED_MEELOGIC::Shared_Ptr_Unique()
{
    std::shared_ptr<Objects> object_ptr_one = std::make_shared<Objects>(5);
    std::shared_ptr<Objects> object_ptr_two (object_ptr_one);

    std::cout << "Is only one pointer pointing to object? : " << std::boolalpha << object_ptr_one.unique() << "\n";
    object_ptr_two.reset(); //Question to the class: Will this delete original object?
    std::cout << "After reseting one shared_ptr, is only one pointer pointing to object? : " << std::boolalpha << object_ptr_one.unique() << "\n";
}


void SHARED_MEELOGIC::Vector_Shared_Pointers_Wrong()
{
    Objects *object_1 = new Objects;
    Objects *object_2 = new Objects;

    std::shared_ptr<Objects> object_1_ptr (object_1);
    std::shared_ptr<Objects> object_2_ptr (object_2);

    std::vector<std::shared_ptr<Objects>> objects_vector_1;
    std::vector<std::shared_ptr<Objects>> objects_vector_2;

    /* What is wrong here? */
    objects_vector_1.emplace_back(object_1);
    objects_vector_1.emplace_back(object_2);

    objects_vector_2.emplace_back(object_1);
    objects_vector_2.emplace_back(object_2);

    std::cout << "Object->number: " << objects_vector_1.at(0)->number << "\n";
    std::cout << "Object->number: " << objects_vector_2.at(0)->number << "\n";


    /* Answer:
     * object_1_ptr, objects_2_ptr, objects_vector_1, objects_vector_2 will all delete original Objects.
     * So object_1 will be deleted 3 times, and object_2 likewise.*/
}

void SHARED_MEELOGIC::Vector_Shared_Pointers_Correct()
{
    Objects *object_1 = new Objects;
    Objects *object_2 = new Objects;

    std::shared_ptr<Objects> object_1_ptr (object_1);
    std::shared_ptr<Objects> object_2_ptr (object_2);

    std::vector<std::shared_ptr<Objects>> objects_vector_1;
    std::vector<std::shared_ptr<Objects>> objects_vector_2;

    objects_vector_1.emplace_back(object_1_ptr);
    objects_vector_1.emplace_back(object_2_ptr);

    objects_vector_2.emplace_back(object_1_ptr);
    objects_vector_2.emplace_back(object_2_ptr);

    std::cout << "Object->number: " << objects_vector_1.at(0)->number << "\n";
    std::cout << "Object->number: " << objects_vector_2.at(0)->number << "\n";


    std::cout << "Reference count: " << object_1_ptr.use_count() << "\n";
    /* Alternatively */
    //std::cout << "Reference count: " << objects_vector_2.at(0).use_count() << "\n";

    objects_vector_1.clear();
    std::cout << "Reference count: " << objects_vector_2.at(0).use_count() << "\n";

    objects_vector_2.clear();
    std::cout << "Reference count: " << object_1_ptr.use_count() << "\n";
}




SHARED_MEELOGIC::Objects::Objects() { std::cout << "Constructor called.\n"; }
SHARED_MEELOGIC::Objects::Objects(int nr) { number = nr; std::cout << "Constructor with parameter called.\n"; }
SHARED_MEELOGIC::Objects::~Objects() { std::cout << "Destructor called.\n"; }

SHARED_MEELOGIC::Objects::Objects(const Objects &other) { std::cout << "Copy constructor called.\n"; std::ignore = other; }
SHARED_MEELOGIC::Objects& SHARED_MEELOGIC::Objects::operator=(const Objects &other)
{ std::cout << "Assignment constructor called.\n"; std::ignore = other; return *this;}

SHARED_MEELOGIC::Objects::Objects(Objects &&other)
{ std::cout << "Move constructor called.\n"; std::ignore = other; }
SHARED_MEELOGIC::Objects& SHARED_MEELOGIC::Objects::operator=(Objects &&other)
{ std::cout << "Move assignment constructor called.\n"; std::ignore = other; return *this; }





struct B;

struct A
{
    std::shared_ptr<B> object_B;
    A() { std::cout << "A constructor. \n"; }
    ~A() { std::cout << "A destructor. \n"; }

    void Set_B(std::shared_ptr<B> b) { object_B = b; }
};

struct B
{
    std::shared_ptr<A> object_A;
    B() { std::cout << "B constructor. \n"; }
    ~B() { std::cout << "B destructor. \n"; }

    void Set_A(std::shared_ptr<A> a) { object_A = a; }
};


void WEAK_MEELOGIC::Circular_Reference()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->Set_B(b);
    b->Set_A(a);
}



void WEAK_MEELOGIC::Dangling_Problem_Bad()
{
    int *number_ptr = new int (10);
    int *number_second_ptr = number_ptr;
    std::cout << *number_second_ptr << "\n";

    delete number_ptr;

    std::cout << *number_second_ptr << "\n"; //Crash or random value.
}


void WEAK_MEELOGIC::Dangling_Problem_Good()
{
    /* Useful for working with objects that are not guaranteed to live for particular time.
     * For example imagine a list of Task objects. If single Task has done it job, it deletes itself.
     * We might have a Timer object which periodically logs which Tasks are still on-going.
     * This Timer could observe Tasks by holding weak_ptr to them. */

    std::shared_ptr<int> number_ptr = std::make_shared<int> (10);
    std::weak_ptr<int> number_second_ptr = number_ptr;

    if(number_second_ptr.expired() == false)
        std::cout << *number_second_ptr.lock() << "\n";

    number_ptr.reset();

    if(number_second_ptr.expired() == false)
        std::cout << *number_second_ptr.lock() << "\n";
    else
        std::cout << "Object is already deleted. \n";
}

void WEAK_MEELOGIC::Start()
{

    //Dangling_Problem_Bad();
    //Dangling_Problem_Good();
    Circular_Reference();
}











