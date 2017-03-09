#include <map>
#include <cassert>
#include <iostream>


namespace MAP_MEELOGIC
{

/*
template< class Key,
        class T,
        class Compare = std::less<Key>,
        class Allocator = std::allocator<std::pair<const Key, T> > >
class map;
*/

    void Map_Insertions()
    {
        int key = 5, value = 0;
        std::map<int, int> numbers_id { {key, value} };

        /* The difference between insert() and operator [] is what happens when there is already an element with the given key. The insert function will not modify the state of the map,
         * but instead return an iterator to the element (and a false indicating that it was not inserted). Operator [] would overwrite previous value. */
        numbers_id[key] = 10; //Postcondition: numbers_id[5] == 10
        assert(numbers_id[key] == 10);

        numbers_id.insert(std::make_pair(key, 20)); //Postcondition: numbers_id[5] == 10. No change.
        assert(numbers_id[key] == 10);

        /* From C++11 we have .emplace() method */
        /* It makes use of variadic templates and perfect forwarding which results in constructing object in place.
         * Instead of getting a source from which to copy into the container, the function takes the parameters that will be forwarded to the constructor of the object stored in the container. */
        numbers_id.emplace(std::make_pair(key, 20)); //Postcondition: numbers_id[5] == 10. No change.
        assert(numbers_id[key] == 10);

    }

    void Map_Iteration()
    {
        int key = 5, value = 0;
        std::map<int, int> numbers_id { {key, value} };

        /* What is wrong with this loop? */
        for(const std::pair<int, int> &entry : numbers_id)
        {
            std::cout << entry.first << " " << entry.second << "\n";
        }


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

        /* This const is required, because std::map is build as std::pair<const Key, T>. Because std::pair<Key, T> is close enough it will create a temporary of the correct type and copy initialize it.
         * That will in turn be copied to the node, creating a total of two copies. */
    }

    void Map_Adjustments()
    {
        int key = 5, key_2 = 10, value = 0, value_2 = 100;
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
         * I already saw in code an example of how a programmer first put all values into the map, and then called std::sort to get top to bottom hierarchy of keys :) */

        /* For more comparision functions visit:
         * http://en.cppreference.com/w/cpp/header/functional*/
    }

    void Start()
    {
        Map_Insertions();
        //Map_Iteration();
        Map_Adjustments();
    }
}
