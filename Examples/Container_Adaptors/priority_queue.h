#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <queue>

namespace PRIORITY_QUEUE_MEELOGIC
{
    void Priority_Queue_Interface();
    void Print_Queue(std::priority_queue<int> numbers);
    void Print_Queue(std::priority_queue<int, std::vector<int>, std::greater<int>> numbers);
    void Start();
}

/* A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element,
 * at the expense of logarithmic insertion and extraction.
 *
 * Working with a priority_queue is similar to managing a heap in some random access container,
 * with the benefit of not being able to accidentally invalidate the heap. */

/* Alternative of using std::priority_queue would be to use vector \ deque and manage heap manually by:
 * std::make_heap, std::push_heap, std::pop_heap, std::sort_heap
 * http://en.cppreference.com/w/cpp/algorithm/sort_heap */



/* Example implementation of std::priority_queue:
 * https://www.quora.com/How-is-priority-queue-implemented-in-C++
 *

template <class T, class Container = std::vector<T>,
          class Compare = std::less<T> >
class priority_queue {
protected:
    Container c;
    Compare comp;

public:
    explicit priority_queue(const Container& c_  = Container(),
                            const Compare& comp_ = Compare())
        : c(c_), comp(comp_)
    {
        std::make_heap(c.begin(), c.end(), comp);
    }

    bool empty()       const { return c.empty(); }
    std::size_t size() const { return c.size(); }

    const T& top()     const { return c.front(); }

    void push(const T& x)
    {
        c.push_back(x);
        std::push_heap(c.begin(), c.end(), comp);
    }

    void pop()
    {
        std::pop_heap(c.begin(), c.end(), comp);
        c.pop_back();
    }
}; */

#endif // PRIORITY_QUEUE_H
