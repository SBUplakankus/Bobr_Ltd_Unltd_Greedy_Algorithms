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

bool knapsack::SortByWeight(Item* a, Item* b)
{
    return a->weight > b->weight;
}

bool knapsack::SortByValue(Item* a, Item* b)
{
    return a->value > b->value;
}

bool knapsack::SortByBestValue(Item* a, Item* b)
{
    return a->valueRatio > b->valueRatio;
}

double knapsack::GetHighestWeightTotal(int weightLimit)
{
    sort(sackOfItems.begin(), sackOfItems.end(), SortByWeight);
    int currentWeight = 0;
    double total = 0;

    for (int i = 0; i < sackOfItems.size(); i++)
    {
        if (currentWeight == weightLimit)
            break;

        if (currentWeight + sackOfItems[i]->weight > weightLimit)
        {
            double remainingWeight = weightLimit - currentWeight;
            double leftoverValue = sackOfItems[i]->value * (remainingWeight / sackOfItems[i]->weight);
            total += leftoverValue;
            break;
        }
        else
        {
            currentWeight += sackOfItems[i]->weight;
            total += sackOfItems[i]->value;
        }
    }

    return total;
}

double knapsack::GetHighestValueTotal(int weightLimit)
{
    return 0.0;
}

double knapsack::GetBestValueTotal(int weightLimit)
{
    return 0.0;
}


