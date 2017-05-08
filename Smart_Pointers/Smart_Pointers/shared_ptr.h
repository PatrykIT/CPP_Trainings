#ifndef SHARED_PTR_H
#define SHARED_PTR_H

namespace SHARED_MEELOGIC
{
    void Start();

    void Shared_Ptr_Contructors_Custom_Class_1();
    void Shared_Ptr_Unique();

    void Vector_Shared_Pointers_Wrong();
    void Vector_Shared_Pointers_Correct();

    struct Objects
    {
        Objects();
        Objects(int nr);
        ~Objects();

        Objects(const Objects &other);
        Objects& operator=(const Objects &other);

        Objects(Objects &&other);
        Objects& operator=(Objects &&other);


        int number = 10;
    };
}

namespace WEAK_MEELOGIC
{
    void Dangling_Problem_Bad();
    void Dangling_Problem_Good();

    void Circular_Reference();

    void Start();
}

#endif // SHARED_PTR_H
