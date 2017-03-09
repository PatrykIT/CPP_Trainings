#include <map>
#include <unordered_map>
#include <fstream>
#include <utility>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

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






    void Exercise_One()
    {
        /* Can this implementation work faster? You can change everything in this implementation.
         * At the end, print all the occurences from biggest to smallest.
         * Fastest implementation wins. */

        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Associative_Containers\\Map_exercises\\words_short.txt";
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
        for(const auto &node : words)
            std::cout << node.first << " = " << node.second << " times.\n";

        std::cout << "\n\n";
        /* Now, when you have counted the occurences, please create a container where occurences are a key. Sorted in top - bottom order */

        std::multimap<int, std::string, std::greater<int>> occurences_correct;
        for(const auto &node : words)
        {
            occurences_correct.emplace(std::make_pair(node.second, node.first));
        }

        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::nano> elapsed_nanoseconds = end - start;
        std::chrono::duration<double, std::milli> elapsed_microseconds = end - start;

        for(const auto &node : occurences_correct)
            std::cout << node.first << " = " << node.second << "\n";


        std::cout << "Elapsed time: " << std::fixed << elapsed_nanoseconds.count() << " nanoseconds.\n";
        std::cout << "Elapsed time: " << std::fixed << elapsed_microseconds.count() << " microseconds. \n";
    }





    void Exercise_One_Answer_Better()
    {
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Associative_Containers\\Map_exercises\\words_short.txt";
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
        for(const auto &node : words)
            std::cout << node.first << " = " << node.second << " times.\n";

        std::cout << "\n\n";
        /* Now, when you have counted the occurences, please create a container where occurences are a key. Sorted in top - bottom order */

        std::multimap<int, std::string, std::greater<int>> occurences_correct;
        for(const auto &node : words)
        {
            occurences_correct.emplace(std::make_pair(node.second, node.first));
        }

        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::nano> elapsed_nanoseconds = end - start;
        std::chrono::duration<double, std::milli> elapsed_microseconds = end - start;

        for(const auto &node : occurences_correct)
            std::cout << node.first << " = " << node.second << "\n";


        std::cout << "Elapsed time: " << std::fixed << elapsed_nanoseconds.count() << " nanoseconds.\n";
        std::cout << "Elapsed time: " << std::fixed << elapsed_microseconds.count() << " microseconds. \n";
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
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Associative_Containers\\Map_exercises\\words_short.txt";
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
        for(const auto &node : words)
            std::cout << node.first << " = " << node.second << " times.\n";

        std::cout << "\n\n";
        /* Now, when you have counted the occurences, please create a container where occurences are a key. Sorted in top - bottom order */

        std::multimap<int, std::string*> occurences_correct;
//        std::string shit = "Damn";
//        std::string *ptr = &shit;
//        occurences_correct.emplace(std::pair<int, std::string*>(1, ptr));
//        occurences_correct.emplace(std::make_pair(1, ptr));

        for(auto iter = words.begin(); iter != words.end(); ++iter)
        {
            //std::string* work = &(iter->first);
            std::cout << iter->first;
        }

        for(const auto &node : words)
        {
            //std::string* worddd = &(node.first); //If it wont work, change loop to iterator based.

            //occurences_correct.insert(std::make_pair(node.second, &node.first));
            //occurences_correct.emplace(std::make_pair(node.second, &node.first));
            //std::cout << node.second << " " << node.first;
        }

        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::nano> elapsed_nanoseconds = end - start;
        std::chrono::duration<double, std::milli> elapsed_microseconds = end - start;

//        for(const auto &node : occurences_correct)
//            std::cout << node.first << " = " << node.second << "\n";


        std::cout << "Elapsed time: " << std::fixed << elapsed_nanoseconds.count() << " nanoseconds.\n";
        std::cout << "Elapsed time: " << std::fixed << elapsed_microseconds.count() << " microseconds. \n";
    }

    void Start()
    {
        //Exercise_One();
        //Exercise_One_Answer_Better();
        Exercise_One_Answer_Best();
    }
}
