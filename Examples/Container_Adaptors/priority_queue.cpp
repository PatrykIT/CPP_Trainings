/* Visualization: https://www.cs.usfca.edu/~galles/visualization/Heap.html */
/* Show comparision with red black tree:
 * https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
 * https://visualgo.net/heap */

#include <queue>
#include <iostream>
#include <functional>

namespace PRIORITY_QUEUE_MEELOGIC
{

/*
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type> >
class priority_queue;
*/

    void Print_Queue(std::priority_queue<int> numbers)
    {
        while(!numbers.empty())
        {
            std::cout << numbers.top() << "\n";
            numbers.pop();
        }
        std::cout << "\n";
    }

    /* Function overload. Needed. */
    void Print_Queue(std::priority_queue<int, std::vector<int>, std::greater<int>> numbers)
    {
        while(!numbers.empty())
        {
            /* Access top element */
            std::cout << numbers.top() << "\n";
            /* Remove top element. */
            numbers.pop();
        }
        std::cout << "\n";
    }

    void Priority_Queue_Interface()
    {
        std::priority_queue<int> number_queue; //We can not use brace initialization here {}.
        //Container adaptors do not use std::initializer_list for construction. See here: http://stackoverflow.com/questions/10293302/why-cant-i-construct-a-queue-stack-with-brace-enclosed-initializer-lists-c1

        std::initializer_list<int> numbers_list = {5, 10, 20, 40, 3, 2, 1};
        //for(int number : numbers_list)
        for(int number : {5, 10, 20, 40, 3, 2, 1}) //Same as above, but shorter, more readable.
        {
            number_queue.push(number);
        }

        /* Below iteration doesn't work. It is because container adaptors purposefully provide a limited interface, which excludes iteration.
         * http://en.cppreference.com/w/cpp/container/priority_queue && http://en.cppreference.com/w/cpp/container/deque */

        //for(auto number : number_queue)
            //std::cout << number << "\n";

        Print_Queue(number_queue);


        /* Change sorting order */
        std::priority_queue<int, std::vector<int>, std::greater<int> > numbers_queue_2;
        for(int number : numbers_list)
            numbers_queue_2.emplace(number);

        Print_Queue(numbers_queue_2);
    }

    void Exercise_One()
    {
        /* Create priority_queue out of std::vector, using constructor (1):
         * priority_queue( const Compare& compare, const Container& cont ); (since C++11)
         * See here more constructors: http://en.cppreference.com/w/cpp/container/priority_queue/priority_queue
         * Take a look at the same constructor but with note "Until C++11". You will see a breaking change. */

        std::vector<int> numbers_vector {1, 5, 10, 0};

    }

    void Exercise_One_Answer()
    {
        /* Create priority_queue out of std::vector, using constructor (1):
         * priority_queue( const Compare& compare, const Container& cont ); (since C++11)
         * See here more constructors: http://en.cppreference.com/w/cpp/container/priority_queue/priority_queue
         * Take a look at the same constructor but with note "Until C++11". You will see a breaking change. */
        std::vector<int> numbers_vector {1, 5, 10, 0};
        std::priority_queue<int, std::vector<int>> numbers_queue_3 (std::less<int>(), numbers_vector);
        std::priority_queue<int, std::vector<int>, std::greater<int>> numbers_queue_3_alternative(std::greater<int>(), numbers_vector);

        Print_Queue(numbers_queue_3);
    }


    void Start()
    {
        Priority_Queue_Interface();
        Exercise_One();
        Exercise_One_Answer();
    }

}
