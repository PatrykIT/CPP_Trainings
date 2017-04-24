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

    //Vector_Unique_Pointers();
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


void SHARED_MEELOGIC::Shared_Ptr_Unique()
{
    std::shared_ptr<Objects> object_ptr_one = std::make_shared<Objects>(5);
    std::shared_ptr<Objects> object_ptr_two (object_ptr_one);

    std::cout << "Is only one pointer pointing to object? : " << std::boolalpha << object_ptr_one.unique() << "\n";
    object_ptr_two.reset(); //Question to the class: Will this delete original object?
    std::cout << "After reseting one shared_ptr, is only one pointer pointing to object? : " << std::boolalpha << object_ptr_one.unique() << "\n";
}



void SHARED_MEELOGIC::Share_Ownership_Raw_Pointers()
{
    Objects *object = new Objects;

    Objects *object_ptr_1 = object;

    {
        /* Lots of code... */
    }

    Objects *object_ptr_2 = object;

    delete object; //OR: delete object_ptr_1; OR: delete object_ptr_2;

    /* What if someone deletes Object too soon, and then other person tries to access object_ptr_1 or object_ptr_2?
     * Crash. */
}


void SHARED_MEELOGIC::Share_Ownership_Shared_Pointers()
{
    Objects *object = new Objects;

    std::shared_ptr<Objects> object_ptr_1 (object);

    {
        /* Lots of code... */
    }

    std::shared_ptr<Objects> object_ptr_2 (object_ptr_1);

    /* We won't manually delete a object, so there is no chance of dereferencing a deleted pointer.
     * Plus, of course there is no chance for memory leak.*/
}


void SHARED_MEELOGIC::Vector_Unique_Pointers()
{
    Objects *object_1 = new Objects;
    Objects *object_2 = new Objects;

    std::unique_ptr<Objects> object_1_ptr (object_1);
    std::unique_ptr<Objects> object_2_ptr (object_2);

    std::vector<std::unique_ptr<Objects>> objects_vector_1;
    std::vector<std::unique_ptr<Objects>> objects_vector_2;

    objects_vector_1.emplace_back(std::move(object_1_ptr));
    objects_vector_1.emplace_back(std::move(object_2_ptr));

    std::cout << "Object->number: " << objects_vector_1.at(0)->number << "\n";



    /* What is wrong here? */
//    objects_vector_2.emplace_back(std::move(object_1));
//    objects_vector_2.emplace_back(std::move(object_2));

    /* Answer:
     * We make a duplicate of unique pointers, which makes a double delete.
     * There will be 2 constructions and 4 destructions. */




    /* What is wrong here? */
//    objects_vector_2.emplace_back(std::move(object_1_ptr));
//    objects_vector_2.emplace_back(std::move(object_2_ptr));
//    std::cout << "Object->number: " << objects_vector_2.at(0)->number << "\n";

    /* Answer:
     * object_1_ptr and object_2_ptr were already moved from before.
     * So now they are nullptrs, and we are putting empty pointers to vector! */




    /* What is wrong here? */
//    objects_vector_2.emplace_back(std::move(objects_vector_1.at(0)));
//    objects_vector_2.emplace_back(std::move(objects_vector_1.at(1)));
//    std::cout << "Object->number: " << objects_vector_1.at(0)->number << "\n";

    /* Answer:
     * We steal resources from first vector. So now first vector has nullptrs. */
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
    Dangling_Problem_Good();

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
