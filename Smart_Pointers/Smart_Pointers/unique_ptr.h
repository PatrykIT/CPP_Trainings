#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

namespace UNIQUE_MEELOGIC
{
    void Unique_Ptr_Contructors_Custom_Class_1();
    void Unique_Ptr_Contructors_Custom_Class_2();
    void Unique_Ptr_Contructors_Custom_Class_3();
    void Unique_Ptr_Contructors_Moving();

    void Unique_Get();
    void Unique_Release();
    void Unique_Reset();

    void Custom_Deleter_C();
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


        int x = 10;
    };
}

#endif // UNIQUE_PTR_H
