#include "lambdas.h"
#include <iostream>


void LAMBDAS_MEELOGIC::Start()
{
    [] () { std::cout << "I am lambda." << std::endl; }();
}
