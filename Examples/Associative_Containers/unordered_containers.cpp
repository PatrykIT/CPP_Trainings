#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>

/* Visualization: https://www.cs.usfca.edu/~galles/visualization/OpenHash.html */

namespace UNORDERED_MEELOGIC
{

/* template< class Key,
            class T,
            class Hash = std::hash<Key>,
            class KeyEqual = std::equal_to<Key>,
            class Allocator = std::allocator< std::pair<const Key, T> > >
class unordered_map; */

    void Unordered_Map_Interface_Basic()
    {
        /* We're going to skip insert operations and all other operations that are very much similar to std::map. Let's focus on differences */
        std::unordered_map<int, std::string> names = {{1, "Ania"}, {3, "Michal"}, {5, "Patryk" }};

        /* Proof that std::unordered_ containers doesn't sort elements. */
        for(const auto &node : names)
            std::cout << "ID: " << node.first << "\nName:  " << node.second << "\n\n";

        /* This is how hash table looks in memory. */
        std::cout << "This hash table has: " << names.bucket_count() << " buckets.\n";

        for(size_t i = 0; i != names.bucket_count(); ++i)
            std::cout << "Number of elements in the bucket with index: " << i << " = " << names.bucket_size(i) << "\n";

        std::cout << "Average number of elements per bucket: " << names.load_factor() << "\n";


        int key_to_find = 5;
        size_t index_of_a_key = names.bucket(key_to_find);
        std::cout << "Key: " << key_to_find << " is at the index: " << index_of_a_key << "\n";


        /* Rehash takes an existing map and rebuilds a new size of buckets, rehashing in the process and redistributing elements into the new buckets. */
        names.rehash(3);
        std::cout << "\n\nAfter rehashing:\n";
        std::cout << "This hash table has: " << names.bucket_count() << " buckets.\n";

        for(size_t i = 0; i != names.bucket_count(); ++i)
            std::cout << "Number of elements in the bucket with index: " << i << " = " << names.bucket_size(i) << "\n";

        /* Reserve guarantees you that if you don't insert more than the reserved number of elements, there will be no rehashing
         * (i.e. your iterators will remain valid). */
        names.reserve(10);




        /* ITERATIONS. Exactly the same as in std::map. */
        for(std::unordered_map<int, std::string>::iterator node = names.begin(); node != names.end(); node++)
            std::cout << "Key: " << node->first << " Value: " << node->second << "\n";

        for(std::unordered_map<int, std::string>::const_iterator node = names.cbegin(); node != names.cend(); node++)
            std::cout << "Key: " << node->first << " Value: " << node->second << "\n";

        for(const auto &node : names) //C++11
            std::cout << "Key: " << node.first << " Value: " << node.second << "\n";

        std::for_each(names.begin(), names.end(), [](std::pair<const int, std::string> const &node)
        { std::cout << "Key: " << node.first << " Value: " << node.second << "\n"; });
    }










                                                                /* ADVANCED */
    struct Full_Name
    {
        std::string first;
        std::string second;
    };

    /* For more info why we need to use std::hash<T>() please look at: http://en.cppreference.com/w/cpp/string/basic_string/hash */
    struct KeyHash
    {
     std::size_t operator()(const Full_Name& k) const
     {
         return std::hash<std::string>()(k.first) ^
                (std::hash<std::string>()(k.second) << 1);
     }
    };


    struct KeyEqual
    {
     bool operator()(const Full_Name& lhs, const Full_Name& rhs) const
     {
        return lhs.first == rhs.first && lhs.second == rhs.second;
     }
    };


    /*
    template<
        class Key,
        class T,
        class Hash = std::hash<Key>,
        class KeyEqual = std::equal_to<Key>,
        class Allocator = std::allocator< std::pair<const Key, T> >
    > class unordered_map;
    */
    void Unordered_Map_Interface_Advanced()
    {
        std::unordered_map<Full_Name, int, KeyHash, KeyEqual> names =
        {
                { {"John", "Doe"}, 35},
                { {"Mary", "Sue"}, 22}
        };

        for(const auto &node : names)
            std::cout << "Key: " << node.first.first << " " << node.first.second << " = " << node.second << "\n";
    }





    bool Exercise_One()
    {
        /* Please find given key, and if it available, print its value.
         * After printing, remove all elements, and check if container is empty. If it is empty - return true, else: return false. */
        std::unordered_map<int, std::string> names = {{1, "Ania"}, {3, "Michal"}, {5, "Patryk" }, {-20, "Krzysztof" }, {4, "Agata" }, {0, "Pawel" }};
        const int key_to_find = 5;

        return false;
    }

    bool Exercise_One_Answer()
    {
        /* Please find given key, and if it available, print its value.
         * After printing, remove all elements, and check if container is empty. If it is, return true, else: return false. */
        std::unordered_map<int, std::string> names = {{1, "Ania"}, {3, "Michal"}, {5, "Patryk" }, {-20, "Krzysztof" }, {4, "Agata" }, {0, "Pawel" }};
        const int key_to_find = 5;

        auto is_key_available = names.find(key_to_find);
        if(is_key_available != names.end())
        {
            std::cout << is_key_available->second << "\n"; //Faster then .at(), because .find() already returns iterator to found element.
            //std::cout << names.at(key_to_find) << "\n"; //Slower, but also okay. Slower, because it searches the container again.
        }

        names.clear();
        //names.erase(names.begin(), names.end()); //Same as above.
        return names.empty();
    }



void Start()
    {
        //Unordered_Map_Interface_Basic();
        //Unordered_Map_Interface_Advanced();

        std::cout << "Container empty: " << Exercise_One_Answer() << "\n";
    }
}
