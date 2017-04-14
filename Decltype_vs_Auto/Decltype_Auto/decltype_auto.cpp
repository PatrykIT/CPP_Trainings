#include "decltype_auto.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <cassert>


/* http://stackoverflow.com/questions/24109737/what-are-some-uses-of-decltypeauto */
/* http://stackoverflow.com/questions/21369113/what-is-the-difference-between-auto-and-decltypeauto-when-returning-from-a-fun */


int& return_number_by_reference(int &number)
{
    return number;
}

/* This straight-forward syntax is available since C++14.
 * On C++11 it wouldn't compile with error: "Missing trailing return type" */
//auto Return_Number_Wrapper(int &number)
//{
//    return return_number_by_reference(number);
//}


/* This is how it needs to be done in C++11. */
//auto Return_Number_Wrapper(int &number) -> decltype(return_number_by_reference(number))
//{
//    return return_number_by_reference(number);
//}

/* decltype(auto) feature is available since C++14.
 * This is the best, most generic way of returning a value that was passed from another function. */
decltype(auto) Return_Number_Wrapper(int &number)
{
    return return_number_by_reference(number);
}


void MEELOGIC_DECLTYPE_VS_AUTO::Return_Value()
{
    int nr = 5;
    decltype(Return_Number_Wrapper(nr)) number = Return_Number_Wrapper(nr);

    std::cout << "Is int& : " << std::is_same<int&, decltype(number)>::value << "\n";
    std::cout << "Is int : " << std::is_same<int, decltype(number)>::value << "\n";

}


void MEELOGIC_DECLTYPE_VS_AUTO::Evaluation()
{
    std::vector<int> numbers { 1, 5, 10 };

    /* An important property of decltype is that its operand never gets evaluated.
     * For example, you can use an out-of-bounds element access to a vector */
    decltype(numbers[5]) number_decltype = numbers.at(0);
    std::cout << "Is int : " << std::is_same<int, decltype(number_decltype)>::value << "\n";
    std::cout << "Is int& : " << std::is_same<int&, decltype(number_decltype)>::value << "\n";

    auto number_auto = numbers.at(0);
    std::cout << "Is int : " << std::is_same<int, decltype(number_auto)>::value << "\n";
    std::cout << "Is int& : " << std::is_same<int&, decltype(number_auto)>::value << "\n";

    number_decltype = 90;
    //number_auto = 90;

    for(auto nr : numbers)
        std::cout << nr << " ";

    std::cout << "\n";
}

void MEELOGIC_DECLTYPE_VS_AUTO::Initialization_of_Local_Variables()
{
    std::cout << std::boolalpha; //Changes 0 and 1 to false & true.

    /* CONST CASE */
    const int number = 5;

    auto number_auto = number;
    decltype(number) number_decltype = number;


    //std::cout << "Is const int: "<< std::is_same<const int, decltype(number_auto)>::value << "\n";

    //std::cout << "Is const int: " << std::is_same<const int, decltype(number_decltype)>::value << "\n";


    //std::cout << "Is const int: " << std::is_const<decltype(number_decltype)>::value  << '\n';
    //std::cout << "Is const int: " << std::is_const<decltype(number_auto)>::value  << '\n';

    const auto number_auto_const = number;
    //std::cout << "Is const int: " << std::is_const<decltype(number_auto_const)>::value  << '\n';

    /* REFERENCE CASE */
    int number_2 = 10;

    int &reference_to_number = number_2;
    auto reference_to_number_auto = reference_to_number;
    decltype(reference_to_number) reference_to_number_decltype = reference_to_number;

    std::cout << "Is int& : " << std::is_same<int&, decltype(reference_to_number)>::value << "\n";
    std::cout << "Is int& : " << std::is_same<int&, decltype(reference_to_number_auto)>::value << "\n";
    std::cout << "Is int& : " << std::is_same<int&, decltype(reference_to_number_decltype)>::value << "\n";

    auto &reference_to_number_auto_fixed = reference_to_number;
    std::cout << "Is int& : " << std::is_same<int&, decltype(reference_to_number_auto_fixed)>::value << "\n";
}




void MEELOGIC_DECLTYPE_VS_AUTO::Start()
{
    //Initialization_of_Local_Variables();
    Return_Value();
    //Evaluation();





}


