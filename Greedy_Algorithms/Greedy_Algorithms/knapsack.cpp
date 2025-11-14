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

void knapsack::initializeSackOfItems()
{
    sackOfItems.clear();
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        sackOfItems.push_back(new Item(i));
    }
}

void knapsack::displaySackOfItems()
{
    if (sackOfItems[0] == nullptr) return;

    cout << "========== Sack of Items ==========" << endl;

    for (auto item : sackOfItems)
        cout << item->toString() << endl;

    cout << "------------------------------------" << endl << endl;
}

bool knapsack::sortByWeight(Item* a, Item* b)
{
    return a->weight > b->weight;
}

bool knapsack::sortByValue(Item* a, Item* b)
{
    return a->value > b->value;
}

bool knapsack::sortByBestValue(Item* a, Item* b)
{
    return a->valueRatio > b->valueRatio;
}

void knapsack::getHighestWeightTotal(int weightLimit)
{
    cout << "========== Sorted by Weight ==========" << endl;

    // Sort the vector from highest weight to lowest
    sort(sackOfItems.begin(), sackOfItems.end(), sortByWeight);
    int currentWeight = 0;
    double total = 0;

    for (int i = 0; i < sackOfItems.size(); i++)
    {   
        Item* currentItem = sackOfItems[i];

        if (currentWeight == weightLimit)
            break;

        // If the new weight is greater than the limit, add a fraction of the item to fill the remainder
        if (currentWeight + currentItem->weight > weightLimit)
        {
            double remainingWeight = weightLimit - currentWeight;
            double leftoverValue = currentItem->value * (remainingWeight / currentItem->weight);
            total += leftoverValue;
            cout << currentItem->toString() << " ---> " << remainingWeight / currentItem->weight << "% Added" << endl;
            break;
        }
        else
        {
            currentWeight += currentItem->weight;
            total += currentItem->value;
            cout << currentItem->toString() << " ---> 100% Added" << endl;
        }
    }

    cout << "------------------------------------" << endl;
    cout << "Total Value: " << total << endl << endl;
}

void knapsack::getHighestValueTotal(int weightLimit)
{
    cout << "========== Sorted by Value ==========" << endl;

    // Sort the vector from highest value to lowest
    sort(sackOfItems.begin(), sackOfItems.end(), sortByValue);
    int currentWeight = 0;
    double total = 0;

    for (int i = 0; i < sackOfItems.size(); i++)
    {
        Item* currentItem = sackOfItems[i];

        if (currentWeight == weightLimit)
            break;

        // If the new weight is greater than the limit, add a fraction of the item to fill the remainder
        if (currentWeight + currentItem->weight > weightLimit)
        {
            double remainingWeight = weightLimit - currentWeight;
            double leftoverValue = currentItem->value * (remainingWeight / currentItem->weight);
            total += leftoverValue;
            cout << currentItem->toString() << " ---> " << remainingWeight / currentItem->weight << "% Added" << endl;
            break;
        }
        else
        {
            currentWeight += currentItem->weight;
            total += currentItem->value;
            cout << currentItem->toString() << " ---> 100% Added" << endl;
        }
    }

    cout << "------------------------------------" << endl;
    cout << "Total Value: " << total << endl << endl;
}

void knapsack::getBestValueTotal(int weightLimit)
{
    cout << "======== Sorted by Best Value ========" << endl;

    // Sort the vector from highest value to weight ratio to lowest
    sort(sackOfItems.begin(), sackOfItems.end(), sortByBestValue);
    int currentWeight = 0;
    double total = 0;

    for (int i = 0; i < sackOfItems.size(); i++)
    {
        Item* currentItem = sackOfItems[i];

        if (currentWeight == weightLimit)
            break;

        // If the new weight is greater than the limit, add a fraction of the item to fill the remainder
        if (currentWeight + currentItem->weight > weightLimit)
        {
            double remainingWeight = weightLimit - currentWeight;
            double leftoverValue = currentItem->value * (remainingWeight / currentItem->weight);
            total += leftoverValue;
            cout << currentItem->toString() << " ---> " << remainingWeight / currentItem->weight << "% Added" << endl;
            break;
        }
        else
        {
            currentWeight += currentItem->weight;
            total += currentItem->value;
            cout << currentItem->toString() << " ---> 100% Added" << endl;
        }
    }

    cout << "------------------------------------" << endl;
    cout << "Total Value: " << total << endl << endl;
}

void knapsack::displaySackValues()
{
    initializeSackOfItems();
    cout << "GREEDY ALGORITHM KNAPSACK DEMONSTRATION" << endl;
    cout << "Test Weight Total: " << TEST_WEIGHT_LIMIT << endl << endl;
    displaySackOfItems();
    getHighestWeightTotal(TEST_WEIGHT_LIMIT);
    getHighestValueTotal(TEST_WEIGHT_LIMIT);
    getBestValueTotal(TEST_WEIGHT_LIMIT);
}


