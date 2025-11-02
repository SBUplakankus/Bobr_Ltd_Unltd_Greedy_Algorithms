#include "knapsack.h"
#include <iostream>

void knapsack::InitializeSackOfItems()
{
    for (int i = 0; i < 10; i++)
    {
        sackOfItems.push_back(new Item());
    }
}

void knapsack::DisplaySackOfItems()
{
    
}

double knapsack::GetHighestWeightTotal(int weightLimit)
{
    int currentWeight;



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
    double bv1 = (double)a.value / a.weight;
    double bv2 = (double)b.value / b.weight;
    return bv1 > bv2;
}
