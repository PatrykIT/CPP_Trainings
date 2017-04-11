#include "lambdas.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <functional> //std::function

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

    std::sort(humans.begin(), humans.end(), [](const Human &one, const Human &two) { return one.age < two.age; });

    Print_Ages(humans.begin(), humans.end());
}


void LAMBDAS_MEELOGIC::Return_Value()
{
    auto saved_lambda = [](int x) -> double { return x * 10.0; };

    double multiplcation =  saved_lambda(5);
    std::cout << multiplcation << "\n";
}

void LAMBDAS_MEELOGIC::Capturing_Variables_and_Auto_Parameters()
{
   int a = 10;
   double b = 5.5;
   std::string name = "Jan";

   /* Since C++14 parameters to lambda can be auto. */
   auto captured_lambda = [&name, a, &b](auto number) { return number * a + b; };

   auto number = captured_lambda(1);

   std::cout << "Number: " << number << "\n";
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
    /* The types of C++11 lambdas are anonymous and instance-unique.
     * Lambda is an unnamed temporary object of unique unnamed non-union non-aggregate class type, known as closure type. */

    std::string name = "Jane";
    int a = 5;

    std::function<std::string(const double&)> saved_lambda = [&name, a](const double &number) -> std::string
    { if(number > a) return "Ola"; else return "Mariusz"; };

    std::string result = saved_lambda(4);
    std::cout << "Name: " << result << "\n";



    /* This below is EXPERIMENTAL. Lambdas shouldn't be compared, because they don't provide 'operator ==' !
     * This is just for illustration purposes. I actually don't know why this works correctly :) */
    auto lambda_first = [](){};
    auto lambda_second = [](){};

    bool is_same = lambda_first == lambda_second;
    std::cout << "Is same: " << is_same << "\n";

    is_same = lambda_first == lambda_first;
    std::cout << "Is same: " << is_same << "\n";
}







void LAMBDAS_MEELOGIC::Start()
{
    //Comparator_Pre_CPP11();
    //Comparator_Since_CPP11();

    //Return_Value();

    //Calling_Lambda();
    //Mutable();
    //Capturing_Variables();

    Lambdas_Return_Value();

    //Lambda_In_Memory_CPP11();
    //Lambda_In_Memory_CPP14();
}



struct Compiler_Generated_Lambda_CPP11
{
private:
    std::string &name;
    int a;

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

    auto saved_lambda = [&name, a](int number) -> double { if(name == "Jane") return a + 10.0 * number;
                                                           else return a + 10.0; };
    double number = saved_lambda(2);
    std::cout << "Number: " << number << "\n";

    number = Compiler_Generated_Lambda_CPP11(name, a)(4);
    /* Above is a shortcut for:  */
    Compiler_Generated_Lambda_CPP11 object(name, a);
    number = object(4);

    std::cout << "Number: " << number << "\n";
}





struct Compiler_Generated_Lambda_CPP14
{
private:
    std::string &name;
    int a;

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
