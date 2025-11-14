#include "defence_system.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

bool defence_system::sortTargetsByLowestEnergyToKill(Alien* a, Alien* b)
{
	return a->energyToKill < b->energyToKill;
}

void defence_system::populateTargetsList()
{
	currentTargets.clear();
	for (int i = 0; i < ALIEN_TARGETS_TO_POPULATE; i++)
		currentTargets.push_back(new Alien(i));
}

defence_system::defence_system()
{
}

defence_system::~defence_system()
{
	for (auto alien : currentTargets)
		delete alien;
}

void defence_system::displayTargets()
{
	cout << "========== Alien Targets ==========" << endl;

	for (auto alien : currentTargets)
		cout << alien->toString() << endl;

	cout << "------------------------------------" << endl << endl;
}

void defence_system::attackTargets()
{
	cout << "======== Defence System Engaging ========" << endl;

	// Sort the vector of aliens
	sort(currentTargets.begin(), currentTargets.end(), sortTargetsByLowestEnergyToKill);

	currentKills = 0;
	energyRemaining = DEFENCE_SYSTEM_STARTING_ENERGY;

	for (int i = 0; i < currentTargets.size(); i++)
	{
		Alien* currentAlien = currentTargets[i];

		// If the energy remaining is 0 exit the loop
		if (energyRemaining <= 0) break;

		// If the current alien can't be killed with the remaining energy, damage the maximum percentage of its health
		if (energyRemaining - currentAlien->energyToKill < 0)
		{
			double damagePercent = energyRemaining / (double)currentAlien->energyToKill;
			currentAlien->damage(damagePercent);
			cout << currentAlien->toString() << " Status: " << fixed << setprecision(0) << (damagePercent * 100) << "% Damaged" << endl;
			break;
		}
		else
		{
			// Kill the current alien and remove the energy that it took
			energyRemaining -= currentAlien->energyToKill;
			currentAlien->kill();
			currentKills++;
			cout << currentAlien->toString() << " Status: Killed" << endl;
		}
	}

	cout << "------------------------------------" << endl;
	cout << "Total Kills: " << currentKills << endl << endl;
	cout << "------------------------------------" << endl;
}

void defence_system::displayDefenceSystem()
{
	cout << "------------------------------------" << endl;
	cout << "GREEDY ALGORITHM ALIEN DEFENCE SYSTEM DEMONSTRATION" << endl;
	cout << "Test Energy Capacity: " << DEFENCE_SYSTEM_STARTING_ENERGY << endl;
	cout << "Test Alien Count: " << ALIEN_TARGETS_TO_POPULATE << endl << endl;
	populateTargetsList();
	displayTargets();
	attackTargets();
}

