# Greedy Algorithm Code Examples

This document contains the source code used in the greedy algorithm demonstrations.  
Each example includes a short description and the full implementation used in the project.

---

## 1. Alien Defence System

### :page_with_curl: Description
This example demonstrates a greedy strategy where the defence system attacks aliens in ascending order of the energy required to kill them.  
The goal is to maximise the total number of kills before the turret runs out of energy.

### :computer: Greedy Algorithm Code
```cpp

// Static Bool used to sort the aliens in the vector
bool defence_system::sortTargetsByLowestEnergyToKill(Alien* a, Alien* b)
{
    return a->energyToKill < b->energyToKill;
}

// Attack Aliens Greedy Algorithm
void defence_system::attackTargets()
{
    // Sort the vector of targets
    sort(currentTargets.begin(), currentTargets.end(), sortTargetsByLowestEnergyToKill);

    // Set the initial stat parameters
    currentKills = 0;
    energyRemaining = DEFENCE_SYSTEM_STARTING_ENERGY;

    // Loop through the vector until out of energy
    for (int i = 0; i < currentTargets.size(); i++)
    {
        Alien* currentAlien = currentTargets[i];

        // Exit if out of energy
        if (energyRemaining <= 0) break;

        if (energyRemaining - currentAlien->energyToKill < 0)
        {
            // Partially damage alien if not enough energy left to kill it
            double damagePercent = energyRemaining / (double)currentAlien->energyToKill;
            currentAlien->damage(damagePercent);
            break;
        }
        else
        {
            // Kill the alien and remove the energy needed to do so
            energyRemaining -= currentAlien->energyToKill;
            currentAlien->kill();
            currentKills++;
        }
    }
}
```

### :floppy_disk: Source Files
- [Defence System Header File + Alien Struct](../Greedy_Algorithms/Greedy_Algorithms/defence_system.h)
- [Defence System C++ File](../Greedy_Algorithms/Greedy_Algorithms/defence_system.cpp)

---

## 2. Knapsack Problem

### :page_with_curl: Description
This example demonstrates a greedy strategy that generates a set of items from a given list based off of a given weight limit. 
There are three different criteria to showcase the algorithm:
- Store items in order of highest weight
- Store items in order of highest value
- Store items in order of highest value to weight ratio

### :computer: Greedy Algorithm Code
```cpp

// Static bool to sort the items vector by best value to weight ratio
bool knapsack::sortByBestValue(Item* a, Item* b)
{
    return a->valueRatio > b->valueRatio;
}

// Knapsack Greedy Algorithm
void knapsack::getBestValueTotal(int weightLimit)
{
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
            break;
        }
        else
        {
            currentWeight += currentItem->weight;
            total += currentItem->value;
        }
    }
}
```

### :floppy_disk: Source Files
- [Knapsack Header File + Item Struct](../Greedy_Algorithms/Greedy_Algorithms/knapsack.h)
- [Knapsack C++ File](../Greedy_Algorithms/Greedy_Algorithms/knapsack.cpp)


