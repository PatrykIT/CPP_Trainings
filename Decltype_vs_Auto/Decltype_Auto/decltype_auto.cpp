#include "decltype_auto.h"
#include <iostream>
#include <string>
#include <typeinfo>


const int* lookup()
{
    const int *number = new int(10);
    return number;
}

//int* return_lookup()
//{
//    return lookup();
//}

//auto return_lookup() //In C+11 that is not possible! Only starting from C++14
//{
//    return lookup();
//}

//auto return_lookup() -> decltype(lookup()) //This is how it needs to be done in C++11.
//{
//    return lookup();
//}

/* http://stackoverflow.com/questions/24109737/what-are-some-uses-of-decltypeauto */
/* http://stackoverflow.com/questions/21369113/what-is-the-difference-between-auto-and-decltypeauto-when-returning-from-a-fun */
/* This is the best, most generic way of returning a value. */
decltype(auto) return_lookup() //decltype(auto) feature is available since C++14.
{
    return lookup();
}
/* Show how it would return types with : decltype, auto, decltype(auto) */


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
    Initialization_of_Local_Variables();

    const int *third = return_lookup();
    auto third_auto = return_lookup();
    decltype(return_lookup()) third_dec = return_lookup();

    std::cout << *third << " " << *third_dec << " " << *third_auto << "\n";

//    std::cout << *third_dec << " " << *third_auto << "\n";



}


