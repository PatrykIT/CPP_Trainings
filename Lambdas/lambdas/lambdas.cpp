#include "lambdas.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <functional> //std::function
#include <string>
#include <memory>


void LAMBDAS_MEELOGIC::Start()
{
    //Comparator_Pre_CPP11();
    //Comparator_Since_CPP11();

    //Return_Value_CPP11();

    //Capturing_Variables();
    //Capturing_Variables_Reference();
    //Auto_Parameters();


    //Calling_Lambda();
    //Mutable_Keyword();

    //Lambdas_in_std_Function();

    //Lambda_In_Memory_CPP11();
    //Lambda_In_Memory_CPP14();

    //Try();
}


double Multiply(int x)
{
    return x * 10.0;
}

void LAMBDAS_MEELOGIC::Return_Value_CPP03()
{
    double multiplication = Multiply(5);
    std::cout << multiplication << "\n";
}


void LAMBDAS_MEELOGIC::Return_Value_CPP11()
{
    auto saved_lambda = [](int x) -> double { return x * 10.0; };

    double multiplication =  saved_lambda(5);
    std::cout << multiplication << "\n";
}

void LAMBDAS_MEELOGIC::Capturing_Variables()
{
    int a = 10;
    double b = 5.5;

    /* Captures 'a' and 'b' by value. */
    auto captured_lambda = [a, b] () { return a + b; };

    /* Alternative, captures everything by value. */
    //auto captured_lambda = [=] () { return a + b; };

    auto number = captured_lambda(); //Remember about () !! Especially when using auto.
    std::cout << "Number: " << number << "\n";
}

void LAMBDAS_MEELOGIC::Capturing_Variables_Advanced()
{
    int a = 10;
    double b = 5.5;

    /* Capture list has higher priority then arguments. */
    auto captured_lambda = [a, b] (int a, double b) -> double { return a + b; };

    a = 100;
    auto number = captured_lambda(200, 50);
    std::cout << "Number: " << number << "\n";
}


void LAMBDAS_MEELOGIC::Capturing_Variables_Reference()
{
    std::shared_ptr<std::string> shared_name;

    std::function<void()> captured_function;
    {
        std::string *name = new std::string("Michal");
        shared_name.reset(name);

        /* Reference counter will be incremented! */
        auto captured_lambda = [&name, shared_name] () {std::cout << *shared_name << std::endl; };

        /* Reference counter is not incremented. */
        captured_function = [&name, &shared_name] () {std::cout << *shared_name << std::endl; };
    }

    shared_name.reset();
    std::cout << *shared_name << std::endl;

    //captured_lambda();
    captured_function();
}

void LAMBDAS_MEELOGIC::Auto_Parameters()
{
   auto a { 10 };

   /* Since C++14 parameters to lambda can be auto. */
   auto captured_lambda = [a] (auto number) -> double { return number * a; };

   /* Brace construction catches narrowing conversions. */
   int number { captured_lambda(2.0) };

   std::cout << "Number: " << number << "\n";
}

void LAMBDAS_MEELOGIC::Calling_Lambda()
{
    int number = 10;

    /* Why is number still 10? */
    [&number]() { number = 1; };
    std::cout << "Number: " << number << "\n";

    /* Answer: Calling lambda '()' is what changes the number. */
    [&number]() { number = 1; } ();
    std::cout << "Number: " << number << "\n";
}

void LAMBDAS_MEELOGIC::Mutable_Keyword()
{
    /* Lambda requires mutable because by default, a function object should produce the same result every time it's called.
     * This is the difference between an object orientated function and a function using a global variable, effectively. */

    int number = 10;

    /* Compile error. Even though we capture by value (copy), it is by default a const. */
    //auto saved_lambda = [number] () { if(number < 100) number = 1; return number * 5; };

    /* Do keep in mind we are changing a COPY here, not original value. */
    auto saved_lambda = [=]() mutable { if(number < 100) number = 1; return number * 5; };
    number = saved_lambda();

    std::cout << "Number: " << number << "\n";
}


void LAMBDAS_MEELOGIC::Lambdas_in_std_Function()
{
    /* The types of C++11 lambdas are anonymous and instance-unique.
     * Lambda is an unnamed temporary object of unique unnamed non-union non-aggregate class type, known as closure type. */

    std::string name = "Jane";
    int a = 5;

    std::function<std::string(const double&)> saved_lambda = [&name, a](const double &number) -> std::string
    { if(number > a) return "Ola"; else return "Mariusz"; };

    std::string result = saved_lambda(4);
    std::cout << "Name: " << result << "\n";

    /* Instances of std::function can store, copy, and invoke any Callable target -- functions, lambda expressions,
     * bind expressions, or other function objects, as well as pointers to member functions and pointers to data members. */
}




/* ------------------------------------ FUNCTOR EXAMPLE ------------------------------------ */

class Human
{
public:
    int age;
    int height;
    std::string name;

    Human() : name ("Michal") { height = 180; age = rand() % 100;}
};

struct Human_Sort_Function //our Functor
{
    bool operator()(const Human &one, const Human &two)
    {
        return one.age < two.age;
    }
};

template<typename ForwardIT>
void Print_Ages(ForwardIT begin, ForwardIT end)
{
    while(begin != end)
    {
        std::cout << begin->age << " ";
        ++begin;
    }
    std::cout << std::endl;
}

void LAMBDAS_MEELOGIC::Comparator_Pre_CPP11()
{
    srand(time(NULL));
    std::cout << "\tFunctor:\n";

    /* Create 10 humans */
    std::vector<Human> humans (10);
    Print_Ages(humans.begin(), humans.end());

    Human_Sort_Function functor;
    std::sort(humans.begin(), humans.end(), functor);

    Print_Ages(humans.begin(), humans.end());
}

void LAMBDAS_MEELOGIC::Comparator_Since_CPP11()
{
    srand(time(NULL));
    std::cout << "\tLambda:\n";

    std::vector<Human> humans (10);
    Print_Ages(humans.begin(), humans.end());

    std::sort(humans.begin(), humans.end(), [](const Human &one, const Human &two) -> bool { return one.age < two.age; });

    Print_Ages(humans.begin(), humans.end());
}



namespace Exercises
{
    void Find()
    {
        srand(time(NULL));

        std::vector<Human> humans(10);

        std::vector<Human>::iterator found_place = std::find_if(humans.begin(), humans.end(), [](const Human &human) -> bool
        { return human.age == 5; } );

        if(found_place != humans.end())
            std::cout << "Found person! \n";
        else
            std::cout << "Not found. \n";
    }

    void Is_Sorted()
    {
        srand(time(NULL));

        std::vector<Human> humans(10);

        for(const auto &human : humans)
            std::cout << human.age << "\n";

        bool sorted = std::is_sorted(humans.begin(), humans.end(), [](const Human &first, const Human &second)
        { return first.age < second.age; });

        if(sorted)
            std::cout << "Vector is sorted! \n";
        else
            std::cout << "Vector is not sorted! \n";
    }
}


/* ----------------------------------------------------------------------------------------- */






/* ---------------------------- LAMBDAS LAYOUT IN MEMORY (HOW IT IS GENERATED BY COMPILER) ---------------------------- */

void LAMBDAS_MEELOGIC::Normal_Lambda()
{
    std::string name = "Jane";
    int a = 5;

    auto saved_lambda = [&name, a](int number) -> double { if(name == "Jane") return a + 10.0 * number;
                                                           else return a + 10.0; };
    double number = saved_lambda(2);
    std::cout << "Number: " << number << "\n";
}


struct Compiler_Generated_Lambda_CPP11
{
private:
    std::string &name;
    const int a;

public:

    /* Constructor */
    Compiler_Generated_Lambda_CPP11(std::string &_name, int _a) : name(_name), a(_a) { }

    /* If we do not write return type explicitly ("-> double"), then it is: */
    // decltype(a + 10.0) operator ()(int number)
    double operator() (int number)
    {
        if(name == "Jane")
            return a + 10.0 * number;
        else
            return a + 10.0;
    }
};



void LAMBDAS_MEELOGIC::Lambda_In_Memory_CPP11()
{
    std::string name = "Jane";
    int a = 5;

    double number = Compiler_Generated_Lambda_CPP11(name, a)(4);
    /* Above is a shortcut for:  */

    Compiler_Generated_Lambda_CPP11 object(name, a);
    number = object(4);

    std::cout << "Number: " << number << "\n";
}



struct Compiler_Generated_Lambda_CPP14
{
private:
    const std::string &name;
    const int a;

public:

    /* Constructor */
    Compiler_Generated_Lambda_CPP14(std::string &_name, int _a) : name(_name), a(_a) { }

    template <typename Type>
    double operator() (Type number)
    {
        if(name == "Jane")
            return a + 10.0 * number;
        else
            return a + 10.0;
    }
};



void LAMBDAS_MEELOGIC::Lambda_In_Memory_CPP14()
{
    std::string name = "Jane";
    int a = 5;

    auto saved_lambda = [&name, a](auto number) -> double { if(name == "Jane") return a + 10.0 * number;
                                                           else return a + 10.0; };
    double number = saved_lambda(2);
    std::cout << "Number: " << number << "\n";

    number = Compiler_Generated_Lambda_CPP14(name, a)(4);
    std::cout << "Number: " << number << "\n";
}
