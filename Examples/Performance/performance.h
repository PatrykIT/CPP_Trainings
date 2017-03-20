#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <utility>
#include <chrono>

namespace PERFORMANCE_MEELOGIC
{
    void Vector_vs_Array();

    void Print_Allocated_Memory_Size(unsigned long long memory_allocated);
    void Print_Time(const std::chrono::duration<double, std::milli> &time);
    std::chrono::time_point<std::chrono::steady_clock> Start_Time();
    std::chrono::time_point<std::chrono::steady_clock> Stop_Time();
    std::chrono::duration<double, std::milli> Get_Time_Difference(const std::chrono::time_point<std::chrono::steady_clock> &start, std::chrono::time_point<std::chrono::steady_clock> &end);


    void Start();

    void Exercise_One();
    int Exercise_Two_Biggest();
    std::pair<int, int> Exercise_Two_Biggest_Smallest_Continuation();

    /* Exercise 1 */
    void Exercise_One_Answer_Better();
    void Exercise_One_Answer_Better_CPP11();
    void Exercise_One_Answer_Best();


    /* Exercise 2 */
    int Exercise_Two_Biggest_Answer_PriorityQueue();
    int Exercise_Two_Biggest_Answer_Vector();
    int Exercise_Two_Biggest_Answer_Set();

    /* Exercise 2 - showing interesting facts */
    int Exercise_Two_Biggest_Alternative_Dynamic_Input_PriorityQueue();
    int Exercise_Two_Biggest_Alternative_Dynamic_Input_Vector();
    int Exercise_Two_Biggest_Alternative_Dynamic_Input_Set();

    /* Exercise 2.1 */
    std::pair<int, int> Exercise_Two_Biggest_Smallest_PriorityQueues();
    std::pair<int, int> Exercise_Two_Biggest_Smallest_Vector();
    std::pair<int, int> Exercise_Two_Biggest_Smallest_Set();
    std::pair<int, int> Exercise_Two_Biggest_Smallest_MinMax();

}

#endif // PERFORMANCE_H
