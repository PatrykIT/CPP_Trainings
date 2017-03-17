#include "operations.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

bool Our_Own_Predicate(const int number) //Used in STL_MEELOGIC::Find()
{
    return number == sqrt(100.0);
}

bool Sort_Comparator(const int number_1, const int number_2) //Used in STL_MEELOGIC::Sort()
{
    return number_1 > number_2; //Growing order.
}

void Our_Own_UnaryFunction(int &number)
{
    number *= 10;
}

namespace STL_MEELOGIC
{
    void Find()
    {
        std::vector<int> numbers = { 5, 10, 15, 20 };

        std::vector<int>::iterator number = std::find(numbers.begin(), numbers.end(), 15);

        if(number != numbers.end()) { std::cout << *number << "\n"; }
        else {std::cout << "Number not found. \n"; }

        //number = std::find_if(numbers.begin(), numbers.end(), [](const int nr) { return nr ==  sqrt(100.0); } );
        number = std::find_if(numbers.begin(), numbers.end(), Our_Own_Predicate);

        if(number != numbers.end()) { std::cout << *number << "\n"; }
        else { std::cout << "Number not found. \n"; }
    }

    void Sort()
    {
        std::vector<int> numbers = { 1, 5, 3, 0 };

        std::sort(numbers.begin(), numbers.end());
        for(const auto number : numbers) { std::cout << number << " "; } std::cout << "\n\n";


        /* Three variants of the same function - changing sorting order. */
        std::sort(numbers.begin(), numbers.end(), Sort_Comparator);
        for(const auto number : numbers) { std::cout << number << " "; } std::cout << "\n\n";

        std::sort(numbers.begin(), numbers.end(), [](const int number_1, const int number_2)
        { return number_1 > number_2; });
        for(const auto number : numbers) { std::cout << number << " "; } std::cout << "\n\n";

        std::sort(numbers.begin(), numbers.end(), std::greater<int>());
        for(const auto number : numbers) { std::cout << number << " "; } std::cout << "\n\n";
    }

    void AllOf_AnyOf_NoneOf()
    {
        std::vector<int> numbers = { 5, 10, 15, 20 };

        /* Checks if unary predicate returns true for all elements in the range [first, last). */
        if( std::all_of(numbers.begin(), numbers.end(), [](const int number){ return number % 5 == 0; }) )
        {
            std::cout << "All numbers are dividable by 5. \n";
        }

        /* Checks if unary predicate p returns true for at least one element in the range [first, last) */
        if( std::any_of(numbers.begin(), numbers.end(), [](const int number){ return number % 10 == 0; }) )
        {
            std::cout << "At least one number is dividable by 10. \n";
        }

        if( std::none_of(numbers.begin(), numbers.end(), [](const int number){ return number % 50 == 0; }) )
        {
            std::cout << "None of the numbers is dividable by 50. \n";
        }
    }

    void For_Each()
    {
        std::vector<int> numbers = { 5, 10, 15, 20 };

        std::for_each(numbers.begin(), numbers.end(), Our_Own_UnaryFunction);
        for(const auto number : numbers) { std::cout << number << " "; } std::cout << "\n\n";

        std::for_each(numbers.begin(), numbers.end(), [](int &number) { number *= 10; } );
        for(const auto number : numbers) { std::cout << number << " "; } std::cout << "\n\n";
    }

    void Remove()
    {
        /* std::remove doesn't actually erase the element from the container, but it does return the new end iterator which can be passed to
         * container_type::erase to do the REAL removal of the extra elements that are now at the end of the container.
         *
         * The algorithm library provides the remove and remove_if algorithms. Because these algorithms operate
         * on a range of elements denoted by iterators, they have no knowledge of the underlying container or collection.
         * Thus, no elements are actually removed from the container.
         *
         * Rather, all elements which don't fit the remove criteria are brought together to the front of the range,
         * in the same relative order. The remaining elements are left in a valid, but unspecified, state.
         * When this is done, remove returns an iterator pointing one element past the last unremoved element.
         *
         * To actually eliminate elements from the container, remove is combined with the container's erase
         * member function, hence the name "erase–remove idiom". */

        std::vector<int> numbers = { 5, 10, 15, 20, 25, 0, 1, 2, 3, 50};
        auto UnaryPredicate = [](const int number) -> bool { return number % 5 == 0; };

        //std::remove_if(numbers.begin(), numbers.end(), UnaryPredicate);
        numbers.erase(std::remove_if(numbers.begin(), numbers.end(), UnaryPredicate), numbers.end());

        for(const auto number : numbers) { std::cout << number << " "; }
    }


    void Start()
    {
        //Find();
        //Sort();
        //AllOf_AnyOf_NoneOf();
        //For_Each();
        Remove();


        //Exercise_One();
    }

    bool Exercise_One()
    {
        std::vector<int> numbers = { 5, 10, 20, 15, 47, 19, -5, 4, 11, -2, 0, 50};

        std::remove_if(numbers.begin(), numbers.end(), [](const int number){ return number % 5 == 0;  } );
        for(const auto number : numbers) { std::cout << number << " "; }

        return std::is_sorted(numbers.begin(), numbers.end());
    }
}