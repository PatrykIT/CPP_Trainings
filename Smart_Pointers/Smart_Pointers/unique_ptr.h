#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

namespace UNIQUE_MEELOGIC
{
    void CPP_03_Pointers();
    void CPP_03_Exception_Safety();
    void Unique_Ptr_Contructors_1();

    void Unique_Ptr_Contructors_2();
    void Unique_Ptr_Contructors_3();

    void Unique_Ptr_Contructors_Moving();

    void Interfaces();

    void Unique_Ptr_Contructors_Bad_Usage();
    void Unique_Ptr_Contructors_Good_Usage();

    void Unique_Get();
    void Unique_Release();
    void Unique_Reset();

    void Vector_Unique_Pointers();

    void Custom_Deleter_C();
    void Custom_Deleter_CPP11_Wrong();
    void Custom_Deleter_CPP11();

    void Start();

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

#endif // UNIQUE_PTR_H
