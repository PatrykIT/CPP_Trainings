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
    std::chrono::duration<double, std::milli> Get_Time_Difference(const auto &start, const auto &end);


    void Start();

    void Exercise_One();
    void Exercise_One_Answer_Better();
    void Exercise_One_Answer_Better_CPP11();
    void Exercise_One_Answer_Best();


    int Exercise_Two();
    int Exercise_Two_Biggest_Answer_PriorityQueue();
    int Exercise_Two_Biggest_Answer_Vector();
    int Exercise_Two_Biggest_Answer_Set();
    std::pair<int, int> Exercise_Two_Biggest_Smallest();
    std::pair<int, int> Exercise_Two_Biggest_Smallest_Alternative();

    int Exercise_Two_Biggest_Alternative_Dynamic_Input();
    int Exercise_Two_Biggest_Alternative_Second_Dynamic_Input();
}

#endif // PERFORMANCE_H
