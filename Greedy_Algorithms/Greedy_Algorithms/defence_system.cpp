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
	sort(currentTargets.begin(), currentTargets.end(), sortTargetsByLowestEnergyToKill);

	currentKills = 0;
	energyRemaining = DEFENCE_SYSTEM_STARTING_ENERGY;

	for (int i = 0; i < currentTargets.size(); i++)
	{
		Alien* currentAlien = currentTargets[i];

		if (energyRemaining <= 0) break;

		if (energyRemaining - currentAlien->energyToKill < 0)
		{
			double damagePercent = energyRemaining / (double)currentAlien->energyToKill;
			currentAlien->damage(damagePercent);
			cout << currentAlien->toString() << " Status: " << fixed << setprecision(0) << (damagePercent * 100) << "% Damaged" << endl;
			break;
		}
		else
		{
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

