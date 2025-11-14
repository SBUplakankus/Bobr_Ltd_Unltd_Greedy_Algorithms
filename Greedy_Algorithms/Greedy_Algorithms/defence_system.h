#pragma once
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

struct Alien
{
	int id, health, distance;

	Alien(int i)
	{
		id = i;
		health = rand() % 100 + 50;
		distance = rand() % 1000 + 1;
	}

	Alien(int i, int h, int d)
	{
		id = i;
		health = h;
		distance = d;
	}

	~Alien()
	{
	}

	int getEnergyToKill()
	{
		return distance + (health * 5) / 10;
	}

	string toString() const
	{
		ostringstream oss;
		oss << "Alien ID: " << id
			<< " Health: " << health
			<< " Distance: " << distance
			<< " Energy To Kill: " << getEnergyToKill;

		return oss.str();
	}
};
class defence_system
{
	private:
		static const int ALIEN_TARGETS_TO_POPULATE = 10;
		vector<Alien*> currentTargets;
		int energyRemaining;
		int currentKills;

	public:
		defence_system();
		~defence_system();
		void populateTargetsList();
		static bool sortTargetsByLowestEnergyToKill(Alien* a, Alien* b);
		void displayTargets();
		void attackTargets();
		void displayDefenceSystem();
};

