#include <map>
#include <unordered_map>
#include <fstream>
#include <utility>
#include <string>
#include <iostream>
#include <chrono>

namespace PERFORMANCE_MEELOGIC
{
    void Map_vs_UnorderedMap()
    {
        /* Counting occurences - how many duplicate strings are in a file. */
        //https://www.random.org/strings/
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words.txt";
        std::ifstream file(path, std::ios_base::in);

        std::map<std::string, int> words;
        std::string temporary;

        /* START COUNTER */
        if(file.is_open())
        {
            while(!file.eof())
            {
                std::getline(file, temporary);
                words[temporary]++;
            }
        }
        else
            std::cerr << "Couldn't open file.";

        auto stop_iterator = std::next(words.begin(), 100);
        for(auto iter = words.begin(); ; ++iter)
        {
            std::cout << iter->first << " = " << iter->second << " times.\n";

            if(iter == stop_iterator)
            {
                std::cout << "STOP.\n";
                break;
            }
        }

//        for(auto node : words)
//            std::cout << node.first << " = " << node.second << " times.\n";

    }

    void Multimap_vs_UnorderedMultimap()
    {

    }

    void Vector_vs_Array()
    {

    }



    /* Original size should be passed as bytes. */
    void Print_Memory(unsigned long long memory_allocated)
    {
        /* Megabytes */
        if(memory_allocated >= 1000000)
        {
            std::cout << "Memory allocated [MB]: " << memory_allocated / 1000000 << " megabytes.\n";
        }
        if(memory_allocated >= 1000)
        {
            std::cout << "Memory allocated [KB]: " << memory_allocated / 1000 << " kilobytes.\n";
        }
        std::cout << "Memory allocated [Bytes]: " << memory_allocated << " bytes.\n";
    }


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

        auto start = std::chrono::steady_clock::now();
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

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed_microseconds = end - start;

        unsigned long long memory_taken = 0;
        for(const auto &node : occurences_correct)
        {
            //std::cout << node.first << " = " << node.second << "\n";
            memory_taken += node.second.capacity();
        }


        std::cout << "Elapsed time: " << std::fixed << elapsed_microseconds.count() << " microseconds. \n";
        Print_Memory(memory_taken);
    }





    void Exercise_One_Answer_Better()
    {
        //const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words_short.txt";
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words.txt";
        std::ifstream file(path, std::ios_base::in);

        std::unordered_map<std::string, int> words;
        std::string temporary;

        auto start = std::chrono::steady_clock::now();
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
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed_microseconds = end - start;

        unsigned long long memory_taken = 0;
        for(const auto &node : occurences_correct)
        {
            //std::cout << node.first << " = " << node.second << "\n";
            memory_taken += node.second.capacity();
            //std::cout << "Str capacity: " << node.second.capacity() << "\n";
        }


        std::cout << "Elapsed time: " << std::fixed << elapsed_microseconds.count() << " microseconds. \n";
        Print_Memory(memory_taken);
    }




    void Exercise_One_Answer_Better_CPP11()
    {
        //const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words_short.txt";
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Performance\\words.txt";
        std::ifstream file(path, std::ios_base::in);

        std::unordered_map<std::string, int> words;
        std::string temporary;

        auto start = std::chrono::steady_clock::now();
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
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed_microseconds = end - start;

        unsigned long long memory_taken = 0;
        for(const auto &node : occurences_correct)
        {
            //std::cout << node.first << " = " << node.second << "\n";
            memory_taken += node.second.capacity();
            //std::cout << "Str capacity: " << node.second.capacity() << "\n";
        }


        std::cout << "Elapsed time: " << std::fixed << elapsed_microseconds.count() << " microseconds. \n";
        Print_Memory(memory_taken);
    }






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

        auto start = std::chrono::steady_clock::now();
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

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> elapsed_microseconds = end - start;

        unsigned long long memory_taken = 0;
        for(const auto &node : occurences_correct)
        {
            //std::cout << node.first << " = " << *node.second << "\n";
            memory_taken += sizeof(node.second); // sizeof(node.second) == sizeof(std::string*)
        }


        std::cout << "Elapsed time: " << std::fixed << elapsed_microseconds.count() << " microseconds. \n";
        Print_Memory(memory_taken);
    }

    void Start()
    {
        //Exercise_One();
        //Exercise_One_Answer_Better();
        //Exercise_One_Answer_Better_CPP11();
        Exercise_One_Answer_Best();
    }
}
