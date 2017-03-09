/* Visualization: https://www.cs.usfca.edu/~galles/visualization/Heap.html */
/* Show comparision with red black tree:
 * https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
 * https://visualgo.net/heap */

#include <queue>
#include <iostream>

namespace PRIORITY_QUEUE_MEELOGIC
{

/*
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
*/

/* A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element,
 * at the expense of logarithmic insertion and extraction.
 *
 * Working with a priority_queue is similar to managing a heap in some random access container,
 * with the benefit of not being able to accidentally invalidate the heap. */


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
        //for(int number : {5, 10, 20, 40, 3, 2, 1}) //Same as below.
        for(int number : numbers_list)
            number_queue.push(number);

        /* Below iteration doesn't work. It is because container adaptors purposefully provide a limited interface, which excludes iteration.
         * http://en.cppreference.com/w/cpp/container/priority_queue && http://en.cppreference.com/w/cpp/container/deque */

        //for(auto number : number_queue)
            //std::cout << number << "\n";

        Print_Queue(number_queue);


        /* Change sorting order */
        std::priority_queue<int, std::vector<int>, std::greater<int> > numbers_queue_2;
        for(int number : numbers_list)
            numbers_queue_2.push(number);
        Print_Queue(numbers_queue_2);


    }


    void Start()
    {
        Priority_Queue_Interface();
    }

}
