#include "knapsack.h"
#include <iostream>
#include <algorithm>

void knapsack::InitializeSackOfItems()
{
    sackOfItems.clear();
    for (int i = 0; i < 10; i++)
    {
        sackOfItems.push_back(new Item());
    }
}

void knapsack::DisplaySackOfItems()
{
    if (sackOfItems[0] == nullptr) return;

    for (auto item : sackOfItems)
        cout << item->ToString() << endl;
}

double knapsack::GetHighestWeightTotal(int weightLimit)
{
    sort(sackOfItems.begin(), sackOfItems.end(), SortByWeight);
    int currentWeight = 0;
    double total = 0;

    for (int i = 0; i < sackOfItems.size(); i++)
    {

    }

    return 0;


}

double knapsack::GetHighestValueTotal(int weightLimit)
{
    return 0.0;
}

double knapsack::GetBestValueTotal(int weightLimit)
{
    return 0.0;
}

bool knapsack::SortByWeight(Item& a, Item& b)
{
    double w1 = a.weight;
    double w2 = b.weight;
    return w1 > w2;
}

bool knapsack::SortByValue(Item& a, Item& b)
{
    double v1 = a.value;
    double v2 = b.value;
    return v1 > v2;
}

bool knapsack::SortByBestValue(Item& a, Item& b)
{
    double bv1 = a.valueRatio;
    double bv2 = b.valueRatio;
    return bv1 > bv2;
}
