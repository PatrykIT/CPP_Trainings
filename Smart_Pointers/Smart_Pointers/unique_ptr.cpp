#include "unique_ptr.h"
#include <memory>
#include <iostream>
#include <functional>
#include <stdio.h>

//TO DO: Show how unique ptr manages deletion when exception is thrown.
//Show how in C++03 we needed to have try catch {} block to delete manually objects.

void UNIQUE_MEELOGIC::Start()
{
    //Unique_Ptr_Interface();
    //Unique_Ptr_Contructors_1();
    //Unique_Ptr_Contructors_2();
    //Unique_Ptr_Contructors_3();

    //Unique_Ptr_Contructors_Moving();

    //Interfaces();

    //Unique_Get();
    //Unique_Release();

    //Custom_Deleter_C();
    Custom_Deleter_CPP11_Wrong();
    //Custom_Deleter_CPP11();

    //Unique_Ptr_Contructors_Bad_Usage();
    //Unique_Ptr_Contructors_Good_Usage();
}



void UNIQUE_MEELOGIC::CPP_03_Pointers()
{
    /* C++03 */
    Objects *object_one_raw_ptr = new Objects();
    Objects *object_two_raw_ptr = new Objects(7);

    delete object_one_raw_ptr;
    delete object_two_raw_ptr;
}


void UNIQUE_MEELOGIC::CPP_03_Exception_Safety()
{
    /* C++03 */
    Objects *object_one_raw_ptr = NULL; // In C++11 please use nullptr instead of NULL.
    Objects *object_two_raw_ptr = NULL;

    try
    {
        object_one_raw_ptr = new Objects();
        object_two_raw_ptr = new Objects(7);
    }
    catch(...)
    {
        if(object_one_raw_ptr != NULL)
            delete object_one_raw_ptr;
        if(object_two_raw_ptr != NULL)
            delete object_two_raw_ptr;
    }

    delete object_one_raw_ptr;
    delete object_two_raw_ptr;
}


void UNIQUE_MEELOGIC::Unique_Ptr_Contructors_1()
{
    /* C++11 */
    std::unique_ptr<Objects> object_one (new Objects);
    std::unique_ptr<Objects> object_two (new Objects(7));
}


void UNIQUE_MEELOGIC::Unique_Ptr_Contructors_2()
{
    Objects *object = new Objects;
    //C / C++03 API that works on raw pointer (like Factory function)
    //...
    //...
    std::unique_ptr<Objects> ptr_to_object (object);
}


void UNIQUE_MEELOGIC::Unique_Ptr_Contructors_3()
{
    std::unique_ptr<Objects> object_one = std::make_unique<Objects>();
    /* make_unique allows us to use 'auto' keyword */
    auto object_two = std::make_unique<Objects>(7);

    std::cout << object_one->x << "\n";
    std::cout << object_two->x << "\n";
}


void UNIQUE_MEELOGIC::Unique_Ptr_Contructors_Moving()
{
    std::unique_ptr<Objects> first_ptr_to_object = std::make_unique<Objects>(5);
    std::cout << first_ptr_to_object->x << "\n";

    //std::unique_ptr<Objects> second_ptr_to_object  = first_ptr_to_object; //Will not compile. Unique_ptr's are not copyable. They are only movable.
    std::unique_ptr<Objects> second_ptr_to_object (std::move(first_ptr_to_object));
    std::cout << second_ptr_to_object->x << "\n";
    /* What is the use-case for moving unique_ptr? */

    //std::cout << first_ptr_to_object->x << "\n"; //Crashes!! Don't touch the pointer that was "moved from".
    if(first_ptr_to_object == nullptr)
        std::cout << "Unique_pointer is empty. Please do not dereference.\n";
    else
        std::cout << first_ptr_to_object->x << "\n";

}




void Take_Object(std::unique_ptr<UNIQUE_MEELOGIC::Objects> object_unique)
{
    /* To take a unique pointer by value means that you are transferring ownership of the pointer to the function.
     * You should expect that the pointer will be modified. */
    std::cout << "std::unique_ptr object" << std::endl;
}

//void Take_Object(std::unique_ptr<UNIQUE_MEELOGIC::Objects> const &object_unique)
//{
//    /* By passing a const&, you are saying that the function can access the Object via the pointer, but can't modify it.
//     * So there is no transfer of ownership, but we know that the pointer will not be changed.
//     * It's okay interface for example printing values etc. */

//    std::cout << "std::unique_ptr const &object" << std::endl;
//}


void Take_Object(const UNIQUE_MEELOGIC::Objects &object_unique)
{
    /* The difference between taking const &object vs. std::unique_ptr const &object is that we require callers to pass
     * original object, not a pointer. That means that they can pass it from unique_ptr, shared_ptr, raw pointer etc.
     * So it is more universal, as callers are not required to use unique_ptr.
     * REMEBER: This is good for const objects, that won't be modified. */
    std::cout << "const &object" << std::endl;
}


void UNIQUE_MEELOGIC::Interfaces()
{
    std::unique_ptr<Objects> object = std::make_unique<Objects>(5);

    /* Real life example of where moving unique_ptr is necessary */
    Take_Object(std::move(object));
    //Take_Object(object);
    //Take_Object(*object);
}




void UNIQUE_MEELOGIC::Unique_Ptr_Contructors_Bad_Usage()
{
    /* What is wrong here? */

    Objects *object = new Objects (5);
    std::unique_ptr<Objects> first_ptr (object);
    std::cout << first_ptr->x << "\n";

    std::unique_ptr<Objects> second_ptr (object);
    std::cout << second_ptr->x << "\n";
}

void UNIQUE_MEELOGIC::Unique_Ptr_Contructors_Good_Usage()
{
    Objects *object = new Objects (5);
    std::unique_ptr<Objects> first_ptr (object);
    std::cout << first_ptr->x << "\n";

    std::unique_ptr<Objects> second_ptr (std::move(first_ptr));
    std::cout << second_ptr->x << "\n";
}





void UNIQUE_MEELOGIC::Unique_Get()
{
    std::unique_ptr<Objects> object = std::make_unique<Objects> ();

    Objects *ptr_to_object = object.get(); //Unique_ptr will stil delete the object at the end of scop (unlike .release() method)

    /* We use .get() if we want to pass a pointer to a function that takes a raw pointer (like every C function). */
}

void UNIQUE_MEELOGIC::Unique_Release()
{
    std::unique_ptr<Objects> object = std::make_unique<Objects> ();

    Objects *ptr_to_object = object.release();
    delete ptr_to_object;
}




void UNIQUE_MEELOGIC::Custom_Deleter_C()
{
    FILE *file_handle;
    file_handle = fopen("Example.txt", "r");

    if(file_handle != NULL)
    {
        std::cout << "File open correctly." << std::endl;
        fclose(file_handle);
    }
}


void UNIQUE_MEELOGIC::Custom_Deleter_CPP11_Wrong()
{
    const std::string path_to_file = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Smart_Pointers\\Smart_Pointers\\Example_Fopen.txt";
    std::unique_ptr<FILE> file_handle_3 (fopen(path_to_file.c_str(), "r"));
    /* What happens when we call delete instead of fclose()? */
}

void UNIQUE_MEELOGIC::Custom_Deleter_CPP11()
{
    const std::string path_to_file = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Smart_Pointers\\Smart_Pointers\\Example_Fopen.txt";

    std::unique_ptr<FILE, // <-- Type of pointer
            decltype(&fclose)>  // <-- Deleter type
            file_handle (fopen(path_to_file.c_str(), "r"), // <-- Returns a pointer.
                         fclose); // <-- Tells unique_ptr which function to call when deleting the pointer.

    /* Instead of decltype, we can write manually deleter type */
    std::unique_ptr<FILE, int(*)(FILE*)> file_handle_2 (fopen(path_to_file.c_str(), "r"), fclose);

    if(file_handle != nullptr)
    {
        std::cout << "File open correctly." << std::endl;
    }
    else
    {
        std::cout << "Sorry." << std::endl;
    }
}




UNIQUE_MEELOGIC::Objects::Objects() { std::cout << "Constructor called.\n"; }
UNIQUE_MEELOGIC::Objects::Objects(int nr) { x = nr; std::cout << "Constructor with parameter called.\n"; }
UNIQUE_MEELOGIC::Objects::~Objects() { std::cout << "Destructor called.\n"; }
UNIQUE_MEELOGIC::Objects::Objects(const Objects &other) { std::cout << "Copy constructor called.\n"; std::ignore = other; }
UNIQUE_MEELOGIC::Objects& UNIQUE_MEELOGIC::Objects::operator=(const Objects &other) { std::cout << "Assignment constructor called.\n"; std::ignore = other; return *this;}
UNIQUE_MEELOGIC::Objects::Objects(Objects &&other) { std::cout << "Move constructor called.\n"; std::ignore = other; }
UNIQUE_MEELOGIC::Objects& UNIQUE_MEELOGIC::Objects::operator=(Objects &&other) { std::cout << "Move assignment constructor called.\n"; std::ignore = other; return *this; }

















