#include "unique_ptr.h"
#include <memory>
#include <iostream>
#include <functional>

#include <stdio.h>


void UNIQUE_MEELOGIC::Start()
{
    //Unique_Ptr_Interface();
    //Unique_Ptr_Contructors_Custom_Class_1();
    //Unique_Ptr_Contructors_Custom_Class_2();
    //Unique_Ptr_Contructors_Custom_Class_3();
    //Unique_Ptr_Contructors_Moving();
    //Unique_Get();
    //Unique_Release();
    //Unique_Reset();
    //Custom_Deleter_C();
    Custom_Deleter_CPP11();
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

    std::unique_ptr<FILE, int(*)(FILE*)> filee (fopen("Example.txt", "r"), fclose);
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

void UNIQUE_MEELOGIC::Unique_Get()
{
    std::unique_ptr<Objects> object = std::make_unique<Objects> ();

    Objects *ptr_to_object = object.get(); //Unique_ptr will stil delete the object at the end of scop (unlike .release() method)
}

void UNIQUE_MEELOGIC::Unique_Release()
{
    std::unique_ptr<Objects> object = std::make_unique<Objects> ();

    Objects *ptr_to_object = object.release();
    delete ptr_to_object;
}

void UNIQUE_MEELOGIC::Unique_Reset()
{
    auto object = std::make_unique<Objects> ();

    object.reset(new Objects(15));

    std::cout << "Objects(15): " << object->x << "\n";
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

















