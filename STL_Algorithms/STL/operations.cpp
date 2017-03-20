#include "operations.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <list>

bool Our_Own_Predicate(const int &number) //Used in STL_MEELOGIC::Find()
{
    return number == sqrt(100.0);
}

bool Sort_Comparator(const int &number_1, const int &number_2) //Used in STL_MEELOGIC::Sort()
{
    return number_1 > number_2; //Growing order.
}

void Our_Own_UnaryFunction(int &number) //Used in STL_MEELOGIC::For_Each()
{
    number *= 10;
}

namespace STL_MEELOGIC
{



    void Iterators_Compability()
    {
        std::vector<int> numbers = { 1, 2, 3, 4 }; //If we change vector to i.e. list, the index loop doesn't compile.

        for(size_t i = 0; i < numbers.size(); ++i)
            std::cout << numbers[i] << " ";

        std::cout << "\n";

        for(auto iter = numbers.begin(); iter != numbers.end(); ++iter) //auto deduces std::vector<int>::iterator
            std::cout << *iter << " ";

        std::cout << "\n\n";
    }

    void Sort()
    {
        std::vector<int> numbers = { 1, 5, 3, 0 };

        std::sort(numbers.begin(), numbers.end());
        for(const auto number : numbers) { std::cout << number << " "; } std::cout << "\n\n";


        /* Three variants of the same function - changing sorting order. */
        std::sort(numbers.begin(), numbers.end(), Sort_Comparator);
        for(const auto number : numbers) { std::cout << number << " "; } std::cout << "\n\n";

        std::sort(numbers.begin(), numbers.end(), [](const int &number_1, const int &number_2)
        { return number_1 > number_2; });
        for(const auto number : numbers) { std::cout << number << " "; } std::cout << "\n\n";

        std::sort(numbers.begin(), numbers.end(), std::greater<int>());
        for(const auto number : numbers) { std::cout << number << " "; } std::cout << "\n\n";



        /* Sorting range of elements. */
        std::vector<int> numbers_2 = { 0, -5, 4, 3, 18, 10, 2 };
        std::stable_sort(numbers_2.begin() +1, numbers_2.end() - 1);
        for(const auto number : numbers_2) { std::cout << number << " "; } std::cout << "\n\n";
    }

    void Find()
    {
        std::vector<int> numbers = { 5, 10, 15, 20 };

        std::vector<int>::iterator number = std::find(numbers.begin(), numbers.end(), 15);

        if(number != numbers.end()) { std::cout << *number << "\n"; }
        else { std::cout << "Number not found. \n"; }

        //number = std::find_if(numbers.begin(), numbers.end(), [](const int nr) { return nr ==  sqrt(100.0); } );
        number = std::find_if(numbers.begin(), numbers.end(), Our_Own_Predicate);

        if(number != numbers.end()) { std::cout << *number << "\n"; }
        else { std::cout << "Number not found. \n"; }
    }


    void AllOf_AnyOf_NoneOf()
    {
        std::vector<int> numbers = { 5, 10, 15, 20 };

        /* Checks if unary predicate returns true for all elements in the range [first, last). */
        if( std::all_of(numbers.begin(), numbers.end(), [](const int &number){ return number % 5 == 0; }) )
        {
            std::cout << "All numbers are dividable by 5. \n";
        }

        /* Checks if unary predicate p returns true for at least one element in the range [first, last) */
        if( std::any_of(numbers.begin(), numbers.end(), [](const int &number){ return number % 10 == 0; }) )
        {
            std::cout << "At least one number is dividable by 10. \n";
        }

        if( std::none_of(numbers.begin(), numbers.end(), [](const int &number){ return number % 50 == 0; }) )
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

        for(auto &number : numbers) //for_each lost some of its popularity due to new for-range loops.
        {
            number *= 10;
        }
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
        auto UnaryPredicate = [](const int &number) -> bool { return number % 5 == 0; };

        //std::remove_if(numbers.begin(), numbers.end(), UnaryPredicate);
        numbers.erase(std::remove_if(numbers.begin(), numbers.end(), UnaryPredicate), numbers.end());

        for(const auto number : numbers) { std::cout << number << " "; }
    }


    void Iterators_Incrementing()
    {
        std::vector<int> numbers_vector = { 5, 10, 15, 20 };
        std::list<int> numbers_list = { 5, 10, 15, 20 };
        int third_number;

        third_number = *(numbers_vector.begin() + 2); //"+" only works for RandomAccessIterator type.
        std::cout << "Third number[vector]: " << third_number << "\n";

        third_number = *std::next(numbers_list.begin(), 2);
        std::cout << "Third number[list]: " << third_number << "\n";
    }

    void Start()
    {
        //Iterators_Compability();
        //Find();
        //Sort();
        //AllOf_AnyOf_NoneOf();
        //For_Each();
        //Remove();
        Iterators_Incrementing();


        //Exercise_One();
        //std::cout << Exercise_Two() << "\n";
        std::cout << Exercise_Two_Answer() << "\n";
    }








// ---------------------------------------------------------------------------------------------------------------------------------
    bool Exercise_One()
    {
        /* 1. Please erase from vector all numbers that are dividable by 5.
         * 2. Check if vector is sorted, and return appriopriate bool value. */
        std::vector<int> numbers = { 5, 10, 20, 15, 47, 19, -5, 4, 11, -2, 0, 50};

    return false;
    }

    bool Exercise_One_Answer()
    {
        std::vector<int> numbers = { 5, 10, 20, 15, 47, 19, -5, 4, 11, -2, 0, 50};

        numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](const int number){ return number % 5 == 0;  } ), numbers.end());
        for(const auto number : numbers) { std::cout << number << " "; }

        return std::is_sorted(numbers.begin(), numbers.end());
    }


// ---------------------------------------------------------------------------------------------------------------------------------

    int Exercise_Two()
    {
        /* 1. Please fill first three numbers with "-1". Try not to use a loop.
         * 2. Reverse this vector.
         * 3. Return maximum element.*/
        std::vector<int> numbers = { 5, 15, 20, 10 };

    return -1;
    }

    int Exercise_Two_Answer()
    {
        std::vector<int> numbers = { 5, 15, 20, 10 };

        std::fill(numbers.begin(), numbers.begin() + 3, -1);
        for(const auto number : numbers) { std::cout << number << " "; }

        std::cout << "\n";

        std::reverse(numbers.begin(), numbers.end());
        for(const auto number : numbers) { std::cout << number << " "; }

        std::vector<int>::iterator max_number_iterator = std::max_element(numbers.begin(), numbers.end());
        int max_number = *max_number_iterator;

        return max_number;
    }
}
