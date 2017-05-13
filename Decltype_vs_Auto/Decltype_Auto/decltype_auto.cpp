#include "decltype_auto.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <cassert>


void MEELOGIC_DECLTYPE_VS_AUTO::Initialization_of_Local_Variables_Const()
{
    std::cout << std::boolalpha; //Changes printing from 0 and 1 to false & true.

    /* CONST CASE */
    const int number = 5;

    auto number_auto = number;
    decltype(number) number_decltype = number;


    //std::cout << "Is const int: "<< std::is_same<const int, decltype(number_auto)>::value << "\n";
    //std::cout << "Is const int: " << std::is_same<const int, decltype(number_decltype)>::value << "\n";

    const auto number_auto_const = number;
    //std::cout << "Is const int: " << std::is_const<decltype(number_auto_const)>::value  << '\n';
}

void MEELOGIC_DECLTYPE_VS_AUTO::Initialization_of_Local_Variables_Reference()
{
    /* REFERENCE CASE */
    int number_2 = 10;

    int& reference_to_number = number_2;
    auto reference_to_number_auto = reference_to_number;
    decltype(auto) reference_to_number_decltype = reference_to_number; //C++14

    std::cout << "Is int& : " << std::is_same<int&, decltype(reference_to_number_auto)>::value << "\n";
    std::cout << "Is int& : " << std::is_same<int&, decltype(reference_to_number_decltype)>::value << "\n";

    auto &reference_to_number_auto_fixed = reference_to_number;
    std::cout << "Is int& : " << std::is_same<int&, decltype(reference_to_number_auto_fixed)>::value << "\n";
}

void MEELOGIC_DECLTYPE_VS_AUTO::Vector_Evaluation_Auto()
{
    std::vector<int> numbers { 1, 5, 10 };

    auto number_auto = numbers.at(0);

    std::cout << "Is int : " << std::is_same<int, decltype(number_auto)>::value << "\n";
    std::cout << "Is int& : " << std::is_same<int&, decltype(number_auto)>::value << "\n";

    number_auto = 90;

    for(auto nr : numbers)
        std::cout << nr << " ";
}

void MEELOGIC_DECLTYPE_VS_AUTO::Vector_Evaluation_Decltype()
{
    std::vector<int> numbers { 1, 5, 10 };

    decltype(numbers[0]) number_decltype = numbers.at(0);

    std::cout << "Is int : " << std::is_same<int, decltype(number_decltype)>::value << "\n";
    std::cout << "Is int& : " << std::is_same<int&, decltype(number_decltype)>::value << "\n";

    number_decltype = 90;

    for(auto nr : numbers)
        std::cout << nr << " ";
}




//http://stackoverflow.com/questions/918567/size-t-vs-containersize-type

std::vector<int> global_numbers { 1, 5, 10 };

decltype(auto) Return_Middle()
{
    if(global_numbers.empty())
        throw std::range_error("Vector is empty!");

    /* Which one is correct? */
    //size_t index = global_numbers.size() / 2;
    //int index = global_numbers.size() / 2;
    //std::vector<int>::size_type index = global_numbers.size() / 2;

    auto index = global_numbers.size() / 2;
    return global_numbers[index];
}

//auto Return_Middle()
//{
//    if(global_numbers.empty())
//        throw std::range_error("Vector is empty!");

//    auto index = global_numbers.size() / 2;
//    return global_numbers[index];
//}


//int Return_Middle()
//{
//    if(global_numbers.empty())
//        throw std::range_error("Vector is empty!");

//    auto index = global_numbers.size() / 2;
//    return global_numbers[index];
//}


//auto Return_Middle() -> decltype(global_numbers[0])
//{
//    if(global_numbers.empty())
//        throw std::range_error("Vector is empty!");

//    auto index = global_numbers.size() / 2;
//    return global_numbers[index];
//}


void MEELOGIC_DECLTYPE_VS_AUTO::Return_Value_Vector()
{
    decltype(auto) number_decltype = Return_Middle();
    auto number_auto = Return_Middle();

    std::cout << std::is_same<int&, decltype(number_decltype)>::value << "\n";
    std::cout << std::is_same<int&, decltype(number_auto)>::value << "\n";
}



/* Exercise 1. :
 * I want this function to be able to return double or int, depending on the user intent. */
//decltype(auto) Function_with_Multiple_Returns()
//{
//    bool return_first = true;
//    if(return_first)
//        return 1.0;
//    else
//        return 1;
//}

namespace ANSWERS
{
    /* Answer to exercise 1: */
    template <typename Type>
    Type Function_with_Multiple_Returns_Answer()
    {
        bool return_first = true;
        if(return_first)
            return 2.5;
        else
            return 1;
    }
}


void MEELOGIC_DECLTYPE_VS_AUTO::Exercises()
{
    auto number_1 = ANSWERS::Function_with_Multiple_Returns_Answer<double>();
    std::cout << "Number 2: " << number_1 << "\n";
}



void MEELOGIC_DECLTYPE_VS_AUTO::Start()
{
    //Initialization_of_Local_Variables_Const();
    //Initialization_of_Local_Variables_Reference();
    //Vector_Evaluation_Auto();
    //Vector_Evaluation_Decltype();

    Return_Value_Vector();

    //Exercises();

}





