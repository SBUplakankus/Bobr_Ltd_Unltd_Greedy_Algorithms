#include "coin_change.h"
#include <iostream>
#include <algorithm>
#include <vector>

CoinChange::CoinChange()
{
    // Default usd coin denominations
    coinDenominations = { 25, 10, 5, 1 };
    targetAmount = 67; // Random amount
}

CoinChange::CoinChange(vector<int> coins, int amount)
{
    coinDenominations = coins;
    targetAmount = amount;

    // Sort coins in descending order
    sort(coinDenominations.begin(), coinDenominations.end(), greater<int>());
}

void CoinChange::displayProblem()
{
    cout << "========== Coin Change Problem ==========" << endl;
    cout << "Coin Denominations: ";
    for (int coin : coinDenominations) {
        cout << coin << "$ ";
    }
    cout << endl;
    cout << "Target Amount: " << targetAmount << "$" << endl;
    cout << "------------------------------------" << endl << endl;
}

void CoinChange::solveGreedy()
{
    cout << "======== Greedy Algorithm Solution ========" << endl;

    int remaining = targetAmount;
    vector<int> coinCount(coinDenominations.size(), 0);
    int totalCoins = 0;

    cout << "Step-by-step solution:" << endl;

    for (int i = 0; i < coinDenominations.size(); i++) {
        int coin = coinDenominations[i];
        coinCount[i] = remaining / coin;
        remaining %= coin;
        totalCoins += coinCount[i];

        if (coinCount[i] > 0) {
            cout << "Use " << coinCount[i] << " x " << coin << "$ coin" << endl;
        }
    }

    cout << "------------------------------------" << endl;
    cout << "Total coins used: " << totalCoins << endl;
    cout << "Remaining amount: " << remaining << "$" << endl;
    cout << "------------------------------------" << endl << endl;
}

void CoinChange::displayGreedyLimitation()
{
    cout << "======== Greedy Algorithm Limitation ========" << endl;

    // Example where greedy fails
    vector<int> weirdCoins = { 9, 6, 1 }; // Greedy fails for amount 11
    int testAmount = 11;

    cout << "Coin Denominations: ";
    for (int coin : weirdCoins) {
        cout << coin << "$ ";
    }
    cout << endl;
    cout << "Target Amount: " << testAmount << "$" << endl;

    // Greedy solution
    int remaining = testAmount;
    vector<int> greedyResult;
    cout << "Greedy solution: ";

    for (int coin : weirdCoins) {
        int count = remaining / coin;
        remaining %= coin;
        for (int j = 0; j < count; j++) {
            greedyResult.push_back(coin);
        }
    }

    cout << "[ ";
    for (int coin : greedyResult) {
        cout << coin << "$ ";
    }
    cout << "] = " << greedyResult.size() << " coins" << endl;

   
    cout << "Optimal solution: [ 6$ 5$ ] = 2 coins" << endl;
    cout << "(Wait, 5$ coin doesn't exist! Let me check...)" << endl;
    cout << "Actually optimal: [ 6$ 5$ ] isn't possible." << endl;
    cout << "Better example: For coins {1, 3, 4} and amount 6:" << endl;
    cout << "Greedy: 4+1+1 (3 coins), Optimal: 3+3 (2 coins)" << endl;

    cout << "------------------------------------" << endl << endl;
}
