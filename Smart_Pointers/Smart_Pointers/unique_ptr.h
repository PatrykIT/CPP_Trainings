#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

namespace UNIQUE_MEELOGIC
{
    void Unique_Ptr_Contructors();
    void Unique_Ptr_Contructors_Custom_Class_1();
    void Unique_Ptr_Contructors_Custom_Class_2();
    void Unique_Ptr_Contructors_Custom_Class_3();

    void Unique_Ptr_Contructors_Moving();

    void Unique_Ptr_Interface();
    void Unique_Ptr_Interface_Extended();

    // Watch out for this: http://stackoverflow.com/questions/16894400/how-to-declare-stdunique-ptr-and-what-is-the-use-of-it
    // Wise words: http://stackoverflow.com/questions/25370628/doesnt-get-break-the-idea-behind-stdunique-ptr
    // Passing pointers: http://stackoverflow.com/questions/8114276/how-do-i-pass-a-unique-ptr-argument-to-a-constructor-or-a-function?rq=1

    // ADD DELETER EXAMPLE!
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
