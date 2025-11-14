
#include <iostream>
#include "knapsack.h"
#include "defence_system.h"
using namespace std;

int main()
{
    srand(time(nullptr));

    knapsack sack;
    sack.displaySackValues();

    defence_system defence;
    defence.displayDefenceSystem();
}
