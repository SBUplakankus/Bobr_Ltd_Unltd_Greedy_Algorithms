#include "defence_system.h"


void defence_system::populateTargetsList()
{

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

bool defence_system::sortTargetsByLowestEnergyToKill(Alien* a, Alien* b)
{
	return false;
}

void defence_system::displayTargets()
{
}

void defence_system::attackTargets()
{
}

