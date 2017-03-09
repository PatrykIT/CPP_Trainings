#include <stack>
#include <list>
#include <iostream>

namespace STACK_MEELOGIC
{

/*
template< class T,
    class Container = std::deque<T> >
class stack;
*/
    void Stack_Interface()
    {
        std::stack<int> numbers;
        numbers.push(5);
        numbers.emplace(10); //Same as above, faster for objects than .push().

        while(!numbers.empty())
        {
            std::cout << numbers.top() << "\n";
            numbers.pop();
        }

        /* Create stack out of list container. */
        std::list<int> list_of_numbers = {5, 0, 10};
        std::stack<int, std::list<int>> numbers_2 (list_of_numbers);
        while(!numbers_2.empty())
        {
            std::cout << numbers_2.top() << "\n";
            numbers_2.pop();
        }
    }

    void Start()
    {
        Stack_Interface();
    }
}
