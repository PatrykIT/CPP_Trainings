#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <queue>
#include <functional>

namespace PRIORITY_QUEUE_MEELOGIC
{
    void Priority_Queue_Interface();
    void Print_Queue(std::priority_queue<int> numbers);
    void Print_Queue(std::priority_queue<int, std::vector<int>, std::greater<int>> numbers);

    void Exercise_One();
    void Exercise_One_Answer();

    void Start();
}

#endif // PRIORITY_QUEUE_H
