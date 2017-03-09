#include <queue>
#include <iostream>

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

    void Start()
    {
        Queue_Interface();
    }
}
