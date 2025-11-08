#include "knapsack.h"
#include <iostream>
#include <algorithm>

knapsack::knapsack()
{
}

knapsack::~knapsack()
{
    for (auto item : sackOfItems)
        delete item;
}

void knapsack::InitializeSackOfItems()
{
    sackOfItems.clear();
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        sackOfItems.push_back(new Item(i));
    }
}

void knapsack::DisplaySackOfItems()
{
    if (sackOfItems[0] == nullptr) return;

    cout << "========== Sack of Items ==========" << endl;

    for (auto item : sackOfItems)
        cout << item->ToString() << endl;

    cout << "------------------------------------" << endl << endl;
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

void knapsack::GetHighestWeightTotal(int weightLimit)
{
    cout << "========== Sorted by Weight ==========" << endl;

    // Sort the vector from highest weight to lowest
    sort(sackOfItems.begin(), sackOfItems.end(), SortByWeight);
    int currentWeight = 0;
    double total = 0;

    for (int i = 0; i < sackOfItems.size(); i++)
    {   
        if (currentWeight == weightLimit)
            break;

        // If the new weight is greater than the limit, add a fraction of the item to fill the remainder
        if (currentWeight + sackOfItems[i]->weight > weightLimit)
        {
            double remainingWeight = weightLimit - currentWeight;
            double leftoverValue = sackOfItems[i]->value * (remainingWeight / sackOfItems[i]->weight);
            total += leftoverValue;
            cout << sackOfItems[i]->ToString() << " ---> " << remainingWeight / sackOfItems[i]->weight << "% Added" << endl;
            break;
        }
        else
        {
            currentWeight += sackOfItems[i]->weight;
            total += sackOfItems[i]->value;
            cout << sackOfItems[i]->ToString() << " ---> 100% Added" << endl;
        }
    }

    cout << "------------------------------------" << endl;
    cout << "Total Value: " << total << endl << endl;
}

void knapsack::GetHighestValueTotal(int weightLimit)
{
    cout << "========== Sorted by Value ==========" << endl;

    // Sort the vector from highest value to lowest
    sort(sackOfItems.begin(), sackOfItems.end(), SortByValue);
    int currentWeight = 0;
    double total = 0;

    for (int i = 0; i < sackOfItems.size(); i++)
    {
        if (currentWeight == weightLimit)
            break;

        // If the new weight is greater than the limit, add a fraction of the item to fill the remainder
        if (currentWeight + sackOfItems[i]->weight > weightLimit)
        {
            double remainingWeight = weightLimit - currentWeight;
            double leftoverValue = sackOfItems[i]->value * (remainingWeight / sackOfItems[i]->weight);
            total += leftoverValue;
            cout << sackOfItems[i]->ToString() << " ---> " << remainingWeight / sackOfItems[i]->weight << "% Added" << endl;
            break;
        }
        else
        {
            currentWeight += sackOfItems[i]->weight;
            total += sackOfItems[i]->value;
            cout << sackOfItems[i]->ToString() << " ---> 100% Added" << endl;
        }
    }

    cout << "------------------------------------" << endl;
    cout << "Total Value: " << total << endl << endl;
}

void knapsack::GetBestValueTotal(int weightLimit)
{
    cout << "======== Sorted by Best Value ========" << endl;

    // Sort the vector from highest value to weight ratio to lowest
    sort(sackOfItems.begin(), sackOfItems.end(), SortByBestValue);
    int currentWeight = 0;
    double total = 0;

    for (int i = 0; i < sackOfItems.size(); i++)
    {
        if (currentWeight == weightLimit)
            break;

        // If the new weight is greater than the limit, add a fraction of the item to fill the remainder
        if (currentWeight + sackOfItems[i]->weight > weightLimit)
        {
            double remainingWeight = weightLimit - currentWeight;
            double leftoverValue = sackOfItems[i]->value * (remainingWeight / sackOfItems[i]->weight);
            total += leftoverValue;
            cout << sackOfItems[i]->ToString() << " ---> " << remainingWeight / sackOfItems[i]->weight << "% Added" << endl;
            break;
        }
        else
        {
            currentWeight += sackOfItems[i]->weight;
            total += sackOfItems[i]->value;
            cout << sackOfItems[i]->ToString() << " ---> 100% Added" << endl;
        }
    }

    cout << "------------------------------------" << endl;
    cout << "Total Value: " << total << endl << endl;
}

void knapsack::DisplaySackValues()
{
    cout << "GREEDY ALGORITHM KNAPSACK DEMONSTRATION" << endl;
    cout << "Test Weight Total: " << TEST_WEIGHT_LIMIT << endl << endl;
    DisplaySackOfItems();
    GetHighestWeightTotal(TEST_WEIGHT_LIMIT);
    GetHighestValueTotal(TEST_WEIGHT_LIMIT);
    GetBestValueTotal(TEST_WEIGHT_LIMIT);
}


