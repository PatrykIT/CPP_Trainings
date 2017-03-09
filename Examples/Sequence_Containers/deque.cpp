#include <deque>
#include <iostream>

namespace DEQUE_MEELOGIC
{
    void Deque_Interface()
    {
        // Create a deque containing integers
        std::deque<int> double_ended_queue = {7, 5, 16, 8};

        /* 4 core methods of double ended queue. */
        double_ended_queue.pop_front();
        double_ended_queue.pop_back();
        double_ended_queue.push_front(10);
        double_ended_queue.push_back(50);

        // Iterate and print values of deque
        for(int number : double_ended_queue)
        {
            std::cout << number << '\n';
        }
    }

    void Start()
    {
        Deque_Interface();
    }
}
