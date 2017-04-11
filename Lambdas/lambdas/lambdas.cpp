#include "lambdas.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

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

    std::sort(humans.begin(), humans.end(), []( const Human &one, const Human &two) { return one.age < two.age; });

    Print_Ages(humans.begin(), humans.end());
}


void LAMBDAS_MEELOGIC::Return_Value()
{
    auto saved_lambda = [](int x) -> double { return x * 10.0; };

    double multiplcation =  saved_lambda(5);
    std::cout << multiplcation << "\n";
}

void LAMBDAS_MEELOGIC::Calling_Lambda()
{
    int number = 10;

    [&number]() { number = 1; };

    std::cout << "Number: " << number << "\n"; //Why is number still 10?
}

void LAMBDAS_MEELOGIC::Mutable()
{
    int number = 10;

    /* Compile error. Even though we captue by value (copy), it is by default a const. */
    //auto saved_lambda = [=]() { if(number < 100) number = 1; return number * 5; };

    /* Do keep in mind we are changing a COPY here, not original value. */
    auto saved_lambda = [=]() mutable { if(number < 100) number = 1; return number * 5; };
    number = saved_lambda();

    std::cout << "Number: " << number << "\n";
}

void LAMBDAS_MEELOGIC::Lambdas_Return_Value()
{
    //TODO. Show what lambda returns (std::function ??)
    //http://stackoverflow.com/questions/21657627/what-is-the-type-signature-of-a-c11-1y-lambda-function
}

void LAMBDAS_MEELOGIC::Capturing_Variables()
{
   int a = 10;
   double b = 5.5;
   std::string name = "Jan";

   /* Since C++14 parameters to lambda can be auto. */
   auto captured_lambda = [&name, a, &b](auto number) { return number * a + b; };

   auto number = captured_lambda(1);

   std::cout << "Number: " << number << "\n";
}


struct Compiler_Generated_Lambda_CPP11
{
private:
    std::string &name;
    int a;

public:

    /* Constructor */
    Compiler_Generated_Lambda_CPP11(std::string &_name, int _a) : name(_name), a(_a) { }

    int operator() (int number)
    {
        if(name == "Jane")
            return a + 10;
        else
            return a - 10;
    }
};


void LAMBDAS_MEELOGIC::Lambda_In_Memory_CPP11()
{
    int a = 5;
    std::string name = "Jane";

    auto saved_lambda = [&name, a](int number) { if(name == "Jane") return a + 10; else return a - 10; };
}


void LAMBDAS_MEELOGIC::Start()
{
    //Comparator_Pre_CPP11();
    //Comparator_Since_CPP11();

    //Return_Value();

    //Calling_Lambda();
    //Mutable();
    Capturing_Variables();
}
