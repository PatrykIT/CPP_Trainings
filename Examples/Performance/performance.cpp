#include <map>
#include <unordered_map>
#include <fstream>
#include <utility>
#include <string>
#include <iostream>

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
}
