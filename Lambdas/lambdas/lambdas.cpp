#include "lambdas.h"
#include <iostream>
#include <vector>
#include <random> // for mt19937, uniform_int_distribution
#include <chrono> // for high_resolution_clock
#include <algorithm>

class Human
{
public:
    int age;
    int height;
    std::string name;
    std::mt19937 eng{std::chrono::high_resolution_clock::now().time_since_epoch().count()};

    Human() : name ("Michal") { height = 180; age = std::uniform_int_distribution<>(1,10)(eng);}
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

}

void LAMBDAS_MEELOGIC::Comparator_Pre_CPP11()
{
    /* Create 10 humans */
    std::vector<Human> humans(10);

//    for(Human &human : humans)
//        std::cout << human.age << " ";
    Print_Ages(humans.begin(), humans.end());

    std::cout << "\n";

    Human_Sort_Function functor;
    std::sort(humans.begin(), humans.end(), functor);

    for(Human &human : humans)
        std::cout << human.age << " ";
}

void LAMBDAS_MEELOGIC::Comparator_Since_CPP11()
{

}



void LAMBDAS_MEELOGIC::Start()
{
    Comparator_Pre_CPP11();


}
