#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

#include <fstream>
#include <utility>
#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>

namespace PERFORMANCE_MEELOGIC
{
    void Vector_vs_Array()
    {

    }



    /* Original size should be passed as bytes. */
    void Print_Allocated_Memory_Size(unsigned long long memory_allocated)
    {
        /* Megabytes */
        if(memory_allocated >= 1000000)
        {
            std::cout << "Memory allocated [MB]: " << memory_allocated / 1000000 << "." << memory_allocated % 1000000 << " megabytes.\n";
        }
        /* Kilobytes */
        if(memory_allocated >= 1000)
        {
            std::cout << "Memory allocated [KB]: " << memory_allocated / 1000 << " kilobytes.\n";
        }
        //std::cout << "Memory allocated [Bytes]: " << memory_allocated << " bytes.\n";
    }


    std::chrono::time_point<std::chrono::steady_clock> Start_Time()
    {
        return std::chrono::steady_clock::now();
    }

    std::chrono::time_point<std::chrono::steady_clock> Stop_Time()
    {
        return std::chrono::steady_clock::now();
    }

    std::chrono::duration<double, std::milli> Get_Time_Difference(const auto &start, const auto &end)
    {
        return end - start;
    }


    void Print_Time(const std::chrono::duration<double, std::milli> &time)
    {
        std::cout << "Elapsed time: " << std::fixed << time.count() << " microseconds. \n";
    }







    /* --------------------------------------------------------------------------------------------------------------------------------------------- */
    /* --------------------------------------------------------------------------------------------------------------------------------------------- */
    /* --------------------------------------------------------------------------------------------------------------------------------------------- */

    void Exercise_One()
    {
        /* Can this implementation work faster? You can change everything in this implementation.
         * At the end, print all the occurences from biggest to smallest.
         * Fastest implementation wins. */

        //const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words_short.txt";
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words.txt";
        std::ifstream file(path, std::ios_base::in);

        std::map<std::string, int> words;
        std::string temporary;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> temporary; //std::getline(file, temporary); //Also works.
                words[temporary]++;
            }
        }
        else
            std::cerr << "Couldn't open file.";


        /* Helper function that prints keys and their values. */
        //for(const auto &node : words)
            //std::cout << node.first << " = " << node.second << " times.\n";

        std::cout << "\n\n";
        /* Now, when you have counted the occurences, please create a container where occurences are a key. Sorted in top - bottom order */

        std::multimap<int, std::string, std::greater<int>> occurences_correct;
        for(const auto &node : words)
        {
            occurences_correct.emplace(std::make_pair(node.second, node.first));
        }

        auto end = Stop_Time();
        std::chrono::duration<double, std::milli> elapsed_microseconds = end - start;

        unsigned long long memory_taken = 0;
        for(const auto &node : occurences_correct)
        {
            //std::cout << node.first << " = " << node.second << "\n";
            memory_taken += node.second.capacity();
        }


        Print_Time(Get_Time_Difference(start, end));
        Print_Allocated_Memory_Size(memory_taken);
    }





    /* Here we use std::unordered_map to load string from file to memory. It is faster then std::map because we do not need to sort strings. */
    void Exercise_One_Answer_Better()
    {
        //const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words_short.txt";
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words.txt";
        std::ifstream file(path, std::ios_base::in);

        std::unordered_map<std::string, int> words;
        std::string temporary;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> temporary; //std::getline(file, temporary); //Also works.
                words[temporary]++;
            }
        }
        else
            std::cerr << "Couldn't open file.";


        /* Helper function that prints keys and their values. */
        //for(const auto &node : words)
            //std::cout << node.first << " = " << node.second << " times.\n";

        std::cout << "\n\n";
        /* Now, when you have counted the occurences, please create a container where occurences are a key. Sorted in top - bottom order */

        std::multimap<int, std::string, std::greater<int>> occurences_correct;
        for(const auto &node : words)
        {
            occurences_correct.emplace(std::make_pair(node.second, node.first));
        }



        /* End of task. Count time and memory taken. */
        auto end = Stop_Time();

        unsigned long long memory_taken = 0;
        for(const auto &node : occurences_correct)
        {
            //std::cout << node.first << " = " << node.second << "\n";
            memory_taken += node.second.capacity();
            //std::cout << "Str capacity: " << node.second.capacity() << "\n";
        }


        Print_Time(Get_Time_Difference(start, end));
        Print_Allocated_Memory_Size(memory_taken);
    }



    /* Here we use std::unordered_map to load string from file to memory + move semantics(std::move).
     * It is faster then std::map because we do not need to sort strings.
     * Move semantics help us with faster construction of strings. That is because we do not copy string contents (which is a lot of chars), but only internal pointers of std::string class.*/
    void Exercise_One_Answer_Better_CPP11()
    {
        //const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words_short.txt";
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words.txt";
        std::ifstream file(path, std::ios_base::in);

        std::unordered_map<std::string, int> words;
        std::string temporary;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> temporary; //std::getline(file, temporary); //Also works.
                words[temporary]++;
            }
        }
        else
            std::cerr << "Couldn't open file.";


        /* Helper function that prints keys and their values. */
        //for(const auto &node : words)
            //std::cout << node.first << " = " << node.second << " times.\n";

        std::cout << "\n\n";
        /* Now, when you have counted the occurences, please create a container where occurences are a key. Sorted in top - bottom order */

        std::multimap<int, std::string, std::greater<int>> occurences_correct;
        for(const auto &node : words)
        {
            occurences_correct.emplace(std::make_pair(node.second, std::move(node.first)));
        }



        /* End of task. Count time and memory taken. */
        auto end = Stop_Time();

        unsigned long long memory_taken = 0;
        for(const auto &node : occurences_correct)
        {
            //std::cout << node.first << " = " << node.second << "\n";
            memory_taken += node.second.capacity();
            //std::cout << "Str capacity: " << node.second.capacity() << "\n";
        }


        Print_Time(Get_Time_Difference(start, end));
        Print_Allocated_Memory_Size(memory_taken);
    }






    /* Here we use std::unordered_map to load string from file to memory. Our multimap where we will sort keys has a value std::string* instead std::string
     * We do not need to create copies of strings, because words are already loaded in std::unordered_map<std::string, int> words.
     * Thanks to having pointers, we save time on copy constructing the string (because simply we don't do it).
     * Second, even bigger advantage is memory saving. There is HUGE difference between keeping std::string and std::string*.
     * For example, if a string has length of 50, it will take at least 50 bytes in memory. Pointer to this string takes only 4 or 8 bytes! */
    struct KeyEqual
    {
     bool operator()(const std::string *lhs, const std::string *rhs) const
     {
        return *lhs < *rhs;
     }
    };

    void Exercise_One_Answer_Best()
    {
        //const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words_short.txt";
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words.txt";
        std::ifstream file(path, std::ios_base::in);

        std::unordered_map<std::string, int> words;
        std::string temporary;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> temporary; //std::getline(file, temporary); //Also works.
                words[temporary]++;
            }
        }
        else
            std::cerr << "Couldn't open file.";


        /* Helper function that prints keys and their values. */
        //for(const auto &node : words)
            //std::cout << node.first << " = " << node.second << " times.\n";

        std::cout << "\n\n";
        /* Now, when you have counted the occurences, please create a container where occurences are a key. Sorted in top - bottom order */

        std::multimap<int, const std::string*> occurences_correct;

        for(const auto &node : words)
        {
            occurences_correct.emplace(std::make_pair(node.second, &node.first));
        }

        auto end = Stop_Time();

        unsigned long long memory_taken = 0;
        for(const auto &node : occurences_correct)
        {
            //std::cout << node.first << " = " << *node.second << "\n";
            memory_taken += sizeof(node.second); // sizeof(node.second) == sizeof(std::string*)
        }


        Print_Time(Get_Time_Difference(start, end));
        Print_Allocated_Memory_Size(memory_taken);
    }










    /* --------------------------------------------------------------------------------------------------------------------------------------------- */
    /* --------------------------------------------------------------------------------------------------------------------------------------------- */
    /* --------------------------------------------------------------------------------------------------------------------------------------------- */

    int Exercise_Two_Biggest()
    {
        /* From given file, return the biggest number. */
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\numbers.txt";
        std::ifstream file(path, std::ios_base::in);

        int current_number;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> current_number;
            }
        }
        else
            std::cerr << "Couldn't open file.";

        auto end = Stop_Time();
        Print_Time(Get_Time_Difference(start, end));

        //Return biggest number.
    }




    /* std::priority_queue */
    int Exercise_Two_Biggest_Answer_PriorityQueue()
    {
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\numbers.txt";
        std::ifstream file(path, std::ios_base::in);

        std::priority_queue<int> biggest;
        int current_file_number;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> current_file_number;
                biggest.push(current_file_number);
            }
        }
        else
            std::cerr << "Couldn't open file.";

        auto end = Stop_Time();
        Print_Time(Get_Time_Difference(start, end));

        return biggest.top();
    }


    /* std::vector + std::sort() */
    int Exercise_Two_Biggest_Answer_Vector()
    {
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\numbers.txt";
        std::ifstream file(path, std::ios_base::in);

        std::vector<int> numbers;
        int current_file_number;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> current_file_number;
                numbers.emplace_back(current_file_number);
            }
        }
        else
            std::cerr << "Couldn't open file.";

        std::sort(numbers.begin(), numbers.end(), [](const int a, const int b) { return a > b; });

        auto end = Stop_Time();
        Print_Time(Get_Time_Difference(start, end));

        return numbers.front();
    }


    /* std::set */
    int Exercise_Two_Biggest_Answer_Set()
    {
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\numbers.txt";
        std::ifstream file(path, std::ios_base::in);

        std::set<int, std::greater<int>> biggest;

        int current_file_number;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> current_file_number;
                biggest.emplace(current_file_number);
            }
        }
        else
            std::cerr << "Couldn't open file.";

        auto end = Stop_Time();
        Print_Time(Get_Time_Difference(start, end));

        return *biggest.begin();
    }


    int Exercise_Two_Biggest_Alternative_Dynamic_Input_PriorityQueue()
    {
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\numbers.txt";
        std::ifstream file(path, std::ios_base::in);

        std::priority_queue<int> biggest;

        int current_file_number;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> current_file_number;
                biggest.emplace(current_file_number);
            }
        }
        else
            std::cerr << "Couldn't open file.";

        biggest.emplace(5000);

        auto end = Stop_Time();
        Print_Time(Get_Time_Difference(start, end));

        return biggest.top();
    }

    /* Comparision of std::sort and std::stable_sort on nearly sorted array. HUGE difference in performance.
     * Note that std::vector is very sensitive to dynamic input - after each insertion, you need to sort whole vector.
     * If you use std::sort (uses Quicksort), then you kill performance. Quicksort is very bad for nearly sorted array.
     * From standard algorithms use std::stable_sort, which is Mergesort. It performs better then Quicksort in that case.
     * The best algorithm for almost sorted container would be Insertion sort. It is not in C++, so feel free to write it yourself. */
    int Exercise_Two_Biggest_Alternative_Dynamic_Input_Vector()
    {
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\numbers.txt";
        std::ifstream file(path, std::ios_base::in);

        std::vector<int> numbers;
        int current_file_number;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> current_file_number;
                numbers.emplace_back(current_file_number);
            }
        }
        else
            std::cerr << "Couldn't open file.";

        std::sort(numbers.begin(), numbers.end(), [](const int a, const int b) { return a > b; });

        numbers.push_back(5000);

        std::sort(numbers.begin(), numbers.end(), [](const int a, const int b) { return a > b; });
        //std::stable_sort(numbers.begin(), numbers.end(), [](const int a, const int b) { return a > b; });

        auto end = Stop_Time();
        Print_Time(Get_Time_Difference(start, end));

        return numbers.front();
    }

    /* std::set is insensitive to dynamic input. For each insertion, it will just create a node with value in appropriate
     * place in the tree. Then it might rebalance the tree. It is much faster then sorting whole vector with standard C++ sorting algorithm.
     * */
    int Exercise_Two_Biggest_Alternative_Dynamic_Input_Set()
    {
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\numbers.txt";
        std::ifstream file(path, std::ios_base::in);

        std::set<int, std::greater<int>> biggest;

        int current_file_number;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> current_file_number;
                biggest.emplace(current_file_number);
            }
        }
        else
            std::cerr << "Couldn't open file.";

        biggest.emplace(5000);

        auto end = Stop_Time();
        Print_Time(Get_Time_Difference(start, end));

        return *biggest.begin();
    }












    /* --------------------------------------------------------------------------------------------------------------------------------------------- */
    /* --------------------------------------------------------------------------------------------------------------------------------------------- */
    /* --------------------------------------------------------------------------------------------------------------------------------------------- */

    std::pair<int, int> Exercise_Two_Biggest_Smallest_Continuation()
    {
        /* From given file, return the biggest and smallest number. */
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\numbers.txt";
        std::ifstream file(path, std::ios_base::in);

        /* This pair should be returned with first element the biggest, and second element the smallest. */
        std::pair<int, int> biggest_lowest;
        int current_number;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> current_number;
            }
        }
        else
            std::cerr << "Couldn't open file.";

        auto end = Stop_Time();
        Print_Time(Get_Time_Difference(start, end));

        return biggest_lowest;
    }



    std::pair<int, int> Exercise_Two_Biggest_Smallest_PriorityQueues()
    {
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\numbers.txt";
        std::ifstream file(path, std::ios_base::in);

        /* This pair should be returned with first element the biggest, and second element the smallest. */
        std::pair<int, int> biggest_lowest;

        std::priority_queue<int> biggest;
        std::priority_queue<int, std::vector<int>, std::greater<typename std::vector<int>::value_type>> lowest;

        int current_file_number;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> current_file_number;
                biggest.push(current_file_number);
                lowest.push(current_file_number);
            }
        }
        else
            std::cerr << "Couldn't open file.";

        biggest_lowest = std::make_pair(biggest.top(), lowest.top());

        auto end = Stop_Time();
        Print_Time(Get_Time_Difference(start, end));

        return biggest_lowest;
    }



    std::pair<int, int> Exercise_Two_Biggest_Smallest_Vector()
    {
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\numbers.txt";
        std::ifstream file(path, std::ios_base::in);

        /* This pair should be returned with first element the biggest, and second element the smallest. */
        std::pair<int, int> biggest_lowest;
        std::vector<int> numbers;
        int current_file_number;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> current_file_number;
                numbers.emplace_back(current_file_number);
            }
        }
        else
            std::cerr << "Couldn't open file.";

        std::sort(numbers.begin(), numbers.end(), [](const int a, const int b) { return a > b; });

        biggest_lowest = std::make_pair(numbers.front(), numbers.back());

        auto end = Stop_Time();
        Print_Time(Get_Time_Difference(start, end));

        return biggest_lowest;
    }




    std::pair<int, int> Exercise_Two_Biggest_Smallest_Set()
    {
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\numbers.txt";
        std::ifstream file(path, std::ios_base::in);

        std::set<int, std::greater<int>> numbers;
        std::pair<int, int> biggest_lowest;

        int current_file_number;

        auto start = Start_Time();
        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> current_file_number;
                numbers.emplace(current_file_number);
            }
        }
        else
            std::cerr << "Couldn't open file.";

        biggest_lowest = std::make_pair(*numbers.begin(), *numbers.rbegin());
        auto end = Stop_Time();
        Print_Time(Get_Time_Difference(start, end));

        return biggest_lowest;
    }


    void Start()
    {
        //Exercise_One();
        //Exercise_One_Answer_Better();
        //Exercise_One_Answer_Better_CPP11();
        //Exercise_One_Answer_Best();


        std::cout << "Biggest element [Priority Queue]: " << Exercise_Two_Biggest_Answer_PriorityQueue() << "\n";
        std::cout << "Biggest element [Vector] : " << Exercise_Two_Biggest_Answer_Vector() << "\n";
        std::cout << "Biggest element [Set]: " << Exercise_Two_Biggest_Answer_Set() << "\n";



        std::cout << "Biggest element with dynamic addition [Priority Queue]: " << Exercise_Two_Biggest_Alternative_Dynamic_Input_PriorityQueue() << "\n";
        std::cout << "Biggest element with dynamic addition: [Vector]" << Exercise_Two_Biggest_Alternative_Dynamic_Input_Vector() << "\n";
        std::cout << "Biggest element with dynamic addition: [Set]" << Exercise_Two_Biggest_Alternative_Dynamic_Input_Set() << "\n";

        std::pair<int, int> answer;

        answer = Exercise_Two_Biggest_Smallest_PriorityQueues();
        std::cout << "Pair [2 priority queues]\nBiggest element: "<< answer.first << "\nSmallest: " << answer.second << "\n";

        answer = Exercise_Two_Biggest_Smallest_Vector();
        std::cout << "Pair [Vector]\nBiggest element: "<< answer.first << "\nSmallest: " << answer.second << "\n";

        answer = Exercise_Two_Biggest_Smallest_Set();
        std::cout << "Pair [Set]\nBiggest element: "<< answer.first << "\nSmallest: " << answer.second << "\n";

    }
}
