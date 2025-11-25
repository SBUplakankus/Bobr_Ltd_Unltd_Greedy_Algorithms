
#include <iostream>
#include "knapsack.h"
#include "defence_system.h"
#include "coin_change.h"
using namespace std;

int main()
{
    // New Random Generation Each Time
    srand(time(nullptr));

    // Display the Knapsack Demonstration
    knapsack sack;
    sack.displaySackValues();

    // Display the Alien Defence Demonstration
    defence_system defence;
    defence.displayDefenceSystem();

    // Display the Coin Change Demonstration
    CoinChange coins;
    coins.displayProblem();
    coins.solveGreedy();
    coins.displayGreedyLimitation();
}
