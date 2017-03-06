/*
Set vs map:

std::set<typeOfFruits> fruits;
fruits.insert (banana);
fruits.insert (apple);
fruits.insert (pineapple);

//it's fast to know if my store sells a type of fruit.
if (fruits.find (pear) == fruits.end())
{ std::cout<<"i don't have pear"; }
a map is useful for storing unique things, plus a 'value'

std::map<typeOfFruits, double> fruits; //Unit price
fruits[banana] = 1.05;
fruits[apple] = 0.85;
fruits[pineapple] = 3.05;
//repeating pineapple will replace the old price (value)
fruits[pineapple] = 3.35;

//it's fast to know how much a fruit costs.
std::map<typeOfFruits, double> itr = fruits.find(pineapple);
if (itr != fruits.end())
{ std::cout<<"pineapples costs: $" <<itr->second; }

*/
