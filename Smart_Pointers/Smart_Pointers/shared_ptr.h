#ifndef SHARED_PTR_H
#define SHARED_PTR_H

namespace SHARED_MEELOGIC
{
    void Start();

    void Shared_Ptr_Contructors_Custom_Class_1();
    void Shared_Ptr_Unique();

    void Share_Ownership_Raw_Pointers();
    void Share_Ownership_Shared_Pointers();

    void Vector_Unique_Pointers();
    void Vector_Shared_Pointers();

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

#endif // SHARED_PTR_H
