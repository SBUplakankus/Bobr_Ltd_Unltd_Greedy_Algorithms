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
