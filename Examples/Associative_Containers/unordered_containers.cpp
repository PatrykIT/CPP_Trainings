#include <unordered_map>
#include <iostream>

namespace UNORDERED_MEELOGIC
{
    void Unordered_Map_Interface_Basic()
    {
        /* We're going to skip insert operations and all other operations that are very much similar to std::map. Let's focus on differences */
        std::unordered_map<int, std::string> names = {{1, "Ania"}, {3, "Michal"}, {5, "Patryk" }};

        /* Proof that std::unordered_ containers doesn't sort elements. */
        for(auto &node : names)
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
    }










                                                                /* ADVANCED */
    struct Key
    {
        std::string first;
        std::string second;
    };

    /* For more info why we need to use std::hash<T>() please look at: http://en.cppreference.com/w/cpp/string/basic_string/hash */
    struct KeyHash
    {
     std::size_t operator()(const Key& k) const
     {
         return std::hash<std::string>()(k.first) ^
                (std::hash<std::string>()(k.second) << 1);
     }
    };


    struct KeyEqual
    {
     bool operator()(const Key& lhs, const Key& rhs) const
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
        std::unordered_map<Key, int, KeyHash, KeyEqual> names =
        {
                { {"John", "Doe"}, 35},
                { {"Mary", "Sue"}, 22}
        };

        for(auto &node : names)
        {
            std::cout << "Key: " << node.first.first << " " << node.first.second << " = " << node.second << "\n";
        }
    }






void Start()
    {
        Unordered_Map_Interface_Basic();
        //Unordered_Map_Interface_Advanced();
    }
}
