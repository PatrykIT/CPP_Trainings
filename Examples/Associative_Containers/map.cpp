#include <map>
#include <cassert>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <string>


namespace MAP_MEELOGIC
{

/*
template< class Key,
        class T,
        class Compare = std::less<Key>,
        class Allocator = std::allocator<std::pair<const Key, T> > >
class map;
*/

    void Map_Interface()
    {
        int key = 5, value = 0;
        std::map<int, int> numbers_id { {key, value} };

        /* INSERTIONS */
        /* Operator [] overrides the value for a given key. */
        numbers_id[key] = 10; //Postcondition: numbers_id[5] == 10
        assert(numbers_id[key] == 10);

        /* The difference between insert() and operator [] is what happens when there is already an element with the given key.
         * The insert function will not modify the state of the map, but instead return an iterator to the element
         * (and a false indicating that it was not inserted). Operator [] would overwrite previous value. */
        //numbers_id.insert(std::make_pair(key, 20)); //Postcondition: numbers_id[5] == 10. No change.
        numbers_id.insert( {key, value} ); //C++11
        assert(numbers_id[key] == 10);

        /* From C++11 we have .emplace() method */
        /* It makes use of variadic templates and perfect forwarding which results in constructing object in place.
         * Instead of getting a source from which to copy into the container,
         * the function takes the parameters that will be forwarded to the constructor of the object stored in the container. */
        numbers_id.emplace(key, 20);
        assert(numbers_id[key] == 10);


        numbers_id[100] = 4; //If the key is not in the map, operator [] will create it.
        assert(numbers_id[100] == 4);
        /* Add code how it could be done .insert or .emplace */



        /* FIND, AT */
        int key_to_find = 5;
        std::map<int, int>::iterator is_key_found = numbers_id.find(key_to_find);
        if(is_key_found != numbers_id.end())
        {
            std::cout << "Key found, it has a mapped value: " << is_key_found->second << "\n";
            std::cout << "Key found, it has a mapped value: " << (*is_key_found).second << "\n";

            std::cout << "Key found, it has a mapped value: " << numbers_id.at(key_to_find) << "\n";
            /* Avoid calling operator [] to get value. If there is no key, it will construct a new one - silent bug.
             * Prefer to call .at() or iterator version. */
            std::cout << "Key found, it has a mapped value: " << numbers_id[key] << "\n";
        }
        else
            std::cout << "Key not found. \n";





        numbers_id.emplace(std::pair<const int, int> {50, 55});
        numbers_id.emplace(std::pair<const int, int> {100, 105});

        /* ITERATIONS */
        for(std::map<int, int>::iterator node = numbers_id.begin(); node != numbers_id.end(); node++)
            std::cout << "Key: " << node->first << " Value: " << node->second << "\n";
            //std::cout << "Key: " << (*node).first << " Value: " << (*node).second << "\n";

        for(std::map<int, int>::const_iterator node = numbers_id.cbegin(); node != numbers_id.cend(); node++)
            std::cout << "Key: " << node->first << " Value: " << node->second << "\n";

        for(const auto &node : numbers_id) //C++11
            std::cout << "Key: " << node.first << " Value: " << node.second << "\n";

        std::for_each(numbers_id.begin(), numbers_id.end(), [](std::pair<const int, int> const &node)
        { std::cout << "Key: " << node.first << " Value: " << node.second << "\n"; });




        /* REMOVING */
        std::cout << "Removing elements.\n";
        numbers_id.erase(key);
        //numbers_id.erase(numbers_id.begin());
        //numbers_id.erase(numbers_id.begin(), numbers_id.end()); //Removes all elements.
        //numbers_id.clear(); //Removes all elements.

        for(const auto &node : numbers_id) //C++11
            std::cout << "Key: " << node.first << " Value: " << node.second << "\n";
    }

    void Map_Adjustments()
    {
        int key = 5, key_2 = 10;
        int value = 0, value_2 = 100;

        std::map<int, int> numbers_id { {key, value}, {key_2, value_2} };

        std::cout << "Map with default comparator: " << "\n";
        for(const auto &entry : numbers_id)
        {
            std::cout << entry.first << " " << entry.second << "\n";
        }


        std::map<int, int, std::greater<int>> numbers_id_adjusted { {key, value}, {key_2, value_2} };

        std::cout << "Map with specified comparator: " << "\n";
        for(const auto &entry : numbers_id_adjusted)
        {
            std::cout << entry.first << " " << entry.second << "\n";
        }

        /* It's useful to remember this 3rd template argument. It is often overlooked or people don't know it exists.
         * I already saw in code an example of how a programmer first put all values into the map, and then copied them into std::vector and called std::sort to get top to bottom hierarchy of keys :) */

        /* For more comparision functions visit:
         * http://en.cppreference.com/w/cpp/header/functional */
    }


    void Multimap()
    {
        std::multimap<int, std::string> multimap_keys;
        std::map<int, std::string> map_keys;

        multimap_keys.emplace(std::make_pair(1, "Michal"));
        multimap_keys.emplace(1, "Mateusz");
        multimap_keys.emplace(std::make_pair(2, "Natalia"));
        multimap_keys.emplace(std::make_pair(1, "Ania"));

        std::cout << "Elements in multimap:" << multimap_keys.size() << "\n";
        for(auto &node : multimap_keys)
            std::cout << "Key: " << node.first << " Value: " << node.second << "\n";

        map_keys.emplace(std::make_pair(1, "Michal"));
        map_keys.emplace(1, "Mateusz");
        map_keys.emplace(std::make_pair(2, "Natalia"));
        map_keys.emplace(std::make_pair(1, "Ania"));

        std::cout << "Elements in map: " << map_keys.size() << "\n";
        for(auto &node : map_keys)
            std::cout << "Key: " << node.first << " Value: " << node.second << "\n";
    }






    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------- */

    void Exercise_One()
    {
        /* Count occurrences of how many times given name appeared in a file. */
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Associative_Containers\\Map_exercises\\words_short.txt";
        std::ifstream file(path, std::ios_base::in);

        std::map<std::string, int> words;
        std::string temporary;

        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> temporary;
                /* Put the name and counter into the map. */
            }
        }
        else
            std::cerr << "Couldn't open file.";

        /* Now, when you have counted the occurences, please create a multimap where occurences are a key and names are values.
         * Keys should be sorted from bigger number to smaller numbers. So the most common occurence is at the top, and the least common occurence at the bottom.
         * Print all elements. */

    }

    void Exercise_One_Answer()
    {
        //https://www.random.org/strings/
        /* Counting occurrences - how many duplicate strings are in a file. */
        const std::string path = "C:\\Users\\cyrklaf.pat\\Documents\\GitHub_SourceTree\\CPP_Trainings\\Examples\\Associative_Containers\\Map_exercises\\words_short.txt";
        std::ifstream file(path, std::ios_base::in);

        std::map<std::string, int> words;
        std::string temporary;

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

        /* Now, when you have counted the occurences, please create a multimap where occurences are a key - in top - bottom order */


        /* Almost good. What is wrong? */
//        std::multimap<int, std::string> occurences;
//        for(const auto &node : words)
//        {
//            occurences.emplace(std::make_pair(node.second, node.first));
//        }

//        for(const auto &node : occurences)
//            std::cout << node.first << " = " << node.second << "\n";



        /* Correct usage */
        std::multimap<int, std::string, std::greater<int>> occurences_correct;
        for(const auto &node : words)
        {
            occurences_correct.emplace(std::make_pair(node.second, node.first));
        }

        for(const auto &node : occurences_correct)
            std::cout << node.first << " = " << node.second << "\n";
    }

    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------- */





    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------- */

    void Exercise_Two()
    {
        int key = 5, value = 0;
        std::map<int, int> numbers_id { {key, value} };

        /* What is wrong with this loop? */
        for(const std::pair<int, int> &entry : numbers_id)
        {
            std::cout << entry.first << " " << entry.second << "\n";
        }
    }

    void Exercise_Two_Answer()
    {
        int key = 5, value = 0;
        std::map<int, int> numbers_id { {key, value} };

        /* Correct loops: */
        for(const std::pair<const int, int> &entry : numbers_id)
        {
            std::cout << entry.first << " " << entry.second << "\n";
        }

        for(const auto &entry : numbers_id)
        {
            std::cout << entry.first << " " << entry.second << "\n";
        }

        /* Confirmation: */
        std::cout << "std::is_same<const pair<int,int>&, decltype( *begin(numbers_id) )>::value = "
             << std::is_same< std::pair<int,int>&,
                                                  decltype(*begin(numbers_id)) >::value << "\n";

        std::cout << "std::is_same<const pair<const int,int>&, decltype( *begin(numbers_id) )>::value = "
             << std::is_same< std::pair<const int,int>&,
                                                        decltype(*begin(numbers_id)) >::value << "\n";

        /* This const is required, because std::map is build as std::pair<const Key, T>. Because std::pair<Key, T> is close enough
         * it will create a temporary of the correct type and copy initialize it.
         * If you don't take node as reference, then that will in turn be copied to the node, creating a total of two copies. */
    }

    /* --------------------------------------------------------------------------------------------------------------------------------------------------------------- */



    void Exercise_Three()
    {
        /* http://en.cppreference.com/w/cpp/container/map/map
         * 1. Create new map using (2).
         * 2. Create new map using (3).
         * Both maps should be created out of "original" */

        std::map<int, std::string> original { {1, "Hallo"}, {5, "Bye"} };
    }

    void Exercise_Three_Answer()
    {
        //http://en.cppreference.com/w/cpp/container/map/map
        //Use (2) and (3)
        std::map<int, std::string> original { {1, "Hallo"}, {5, "Bye"} };

        //(2). Constructor taking iterators.
        std::map<int, std::string> answer_1 (original.begin(), original.end());
        for(const auto &node : answer_1)
            std::cout << node.first << " " << node.second << "\n";

        //(3). Copy constructor taking another map
        std::map<int, std::string> answer_2 (original);
        for(const auto &node : answer_2)
            std::cout << node.first << " " << node.second << "\n";
    }


    void Start()
    {
        //Map_Interface();
        //Map_Adjustments();
        Multimap();

        //Exercise_One();
        //Exercise_One_Answer();

        //Exercise_Two();
        //Exercise_Two_Answer();

        //Exercise_Three();
        //Exercise_Three_Answer();
    }
}
