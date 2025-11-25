#pragma once
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class CoinChange
{
private:
    vector<int> coinDenominations;
    int targetAmount;

public:
    CoinChange();
    CoinChange(vector<int> coins, int amount);

    /// <summary>
    /// Solve using greedy algorithm - always pick largest coin first
    /// </summary>
    void solveGreedy();

    /// <summary>
    /// Display the problem setup
    /// </summary>
    void displayProblem();

    /// <summary>
    /// Display when greedy algorithm fails
  
};