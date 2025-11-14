#include "defence_system.h"
#include <iostream>
#include <algorithm>

bool defence_system::sortTargetsByLowestEnergyToKill(Alien* a, Alien* b)
{
	return a->getEnergyToKill() > b->getEnergyToKill();
}

void defence_system::populateTargetsList()
{
	for (int i = 0; i < ALIEN_TARGETS_TO_POPULATE; i++)
		currentTargets[i] = new Alien(i);

	sort(currentTargets.begin(), currentTargets.end(), sortTargetsByLowestEnergyToKill);
}

defence_system::defence_system()
{
	currentKills = 0;
	populateTargetsList();
}

defence_system::~defence_system()
{
	for (auto alien : currentTargets)
		delete alien;
}

void defence_system::displayTargets()
{
	for (auto alien : currentTargets)
		cout << alien->toString() << endl;
}

void defence_system::attackTargets()
{

}

void defence_system::displayDefenceSystem()
{

}

