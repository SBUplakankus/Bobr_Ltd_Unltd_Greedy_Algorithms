# Greedy Algorithm Code Examples

This document contains the source code used in the greedy algorithm demonstrations.  
Each example includes a short description and the full implementation used in the project.

---

## 1. Alien Defence System

### Description
This example demonstrates a greedy strategy where the defence system attacks aliens in ascending order of the energy required to kill them.  
The goal is to maximise the total number of kills before the turret runs out of energy.

### Greedy Algorithm Code
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
