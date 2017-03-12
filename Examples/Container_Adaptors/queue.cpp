#include <queue>
#include <iostream>
#include <list>

namespace QUEUE_MEELOGIC
{
    void Queue_Interface()
    {
        std::queue<int> numbers_queue;
        numbers_queue.push(10);
        numbers_queue.emplace(20);
        numbers_queue.emplace(5);
        std::cout << "First element: " << numbers_queue.front() << "\n";
        std::cout << "Last element: " << numbers_queue.back() << "\n";

        numbers_queue.pop();
        std::cout << "First element after poping: " << numbers_queue.front() << "\n";
    }

    void Exercise_One()
    {
        /* http://en.cppreference.com/w/cpp/container/queue/queue
         * Create queue that uses std::list<int> as a container.
         * To this queue, put values: 5, 10
         * Print values in queue from first to last.
         * Note: you can delete values when printing.
         *
         * Note: you don't need to know the implementation of std::list.
         * All you need is a std::queue interface.
         * That is why we call it "Container Adaptor". */
    }

    void Exercise_One_Answer()
    {
        /* http://en.cppreference.com/w/cpp/container/queue/queue
         * Create queue that uses std::list<int> as a container.
         * To this queue, put values: 5, 10, 15
         * Print values in queue from first to last.
         * Note: you can delete values when printing. */

        std::queue<int, std::list<int>> answer;
        answer.emplace(5); //or .push()
        answer.emplace(10);
        answer.emplace(15);

        while(!answer.empty())
        {
            std::cout << answer.front() << "\n";
            answer.pop();
        }
    }

    void Start()
    {
        //Queue_Interface();
        //Exercise_One();
        Exercise_One_Answer();
    }
}
