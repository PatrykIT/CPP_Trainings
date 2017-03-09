#include <array>
#include <iostream>
#include <algorithm>

namespace ARRAY_MEELOGIC
{
    void CPP11_Array()
    {
        const int size = 3;
        std::array<int, size> numbers = {7, 5, 10};

        /* ELEMENTS COUNT */
        std::cout << "Number of elements in array: " << numbers.size() << "\n";

        /* EMPTINESS */
        if(!numbers.empty())
        {

        }

        for(unsigned i = 0; i < numbers.size(); ++i)
            std::cout << "Value: " << numbers[i] << "\n";

        /* SORTING */
        std::cout << "\nSort operation:\n";
        std::sort(numbers.begin(), numbers.end());
        for(auto nr : numbers)
            std::cout << "Value: " << nr << "\n";

        /* FILLING */
        std::cout << "\nFill operation:\n";
        numbers.fill(0);
        for(auto iter = numbers.begin(); iter != numbers.end(); ++iter)
            std::cout << "Value: " << *iter << "\n";

        /* BOUNDS CHECKING */
        //std::cout << numbers.at(4); //Will throw exception of type: std::out_of_range.
        //That is good, because it is easy to trace the bug in code.
    }

    void C_Style_Array()
    {
        const unsigned size = 3;
        int numbers[size] = {7, 5, 10}; //Also could be written as int numbers[] = {1, 5, 10}

        /* ELEMENTS COUNT */
        std::cout << "Number of elements in array: " << sizeof(numbers) / sizeof(numbers[0]) << "\n";

        /* EMPTINESS */
        if(sizeof(numbers) > 0)
        {

        }

        for(unsigned i = 0; i < sizeof(numbers) / sizeof(numbers[0]); ++i)
            std::cout << "Value: " << numbers[i] << "\n";

        /* SORTING */
        std::cout << "\nSort operation:\n";
        std::sort(numbers, numbers + size);
        for(auto nr : numbers)
            std::cout << "Value: " << nr << "\n";

        /* FILLING */
        std::cout << "\nFill operation:\n";
        for(auto &nr : numbers) //Have to remember to take &nr, not nr !!!
            nr = 0;
        for(auto nr : numbers)
            std::cout << "Value: " << nr << "\n";

        /* BOUNDS CHECKING */
        //std::cout << numbers[4]; //No bounds checking. Undefined behaviour.
        //Will crash or print some random value. Hard to trace in code.
    }

    void Start()
    {
        std::cout << "\tC++11 array:\n";
        CPP11_Array();

        std::cout << "\tC-style array:\n";
        C_Style_Array();
    }
}
