#include <set>
#include <map>
#include <iostream>

namespace SET_MEELOGIC
{
    void Set_Map_Differences()
    {
        enum typeOfFruits { banana, apple, pineapple, pear };

        std::set<typeOfFruits> fruits;
        fruits.insert (banana);
        fruits.insert (apple);
        fruits.insert (pineapple);

        //it's fast to know if my store sells a type of fruit.
        if (fruits.find (pear) != fruits.end())
            std::cout << "Pear is available.\n";
        else
            std::cout << "Pear is not available. Come back later.\n";


        //a map is useful for storing unique things, plus a 'value'
        std::map<typeOfFruits, double> fruits_with_prices; //Unit price
        fruits_with_prices[banana] = 1.05;
        fruits_with_prices[apple] = 0.85;
        fruits_with_prices[pineapple] = 3.05;
        //repeating pineapple will replace the old price (value)
        fruits_with_prices[pineapple] = 4.35;

        //it's fast to know how much a fruit costs.
        std::map<typeOfFruits, double>::iterator itr = fruits_with_prices.find(pineapple);
        if (itr != fruits_with_prices.end())
            std::cout << "Pineapples costs: " << itr->second << " $\n";
    }

    void Start()
    {
        Set_Map_Differences();
    }
}
