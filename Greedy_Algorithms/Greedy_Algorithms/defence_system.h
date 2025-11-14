#pragma once
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

struct Alien
{
	int id, health, distance, energyToKill;

	Alien(int i)
	{
		id = i;
		health = rand() % 100 + 1;
		distance = rand() % 100 + 1;
		energyToKill = distance + (health * 2) / 10;
	}

	Alien(int i, int h, int d)
	{
		id = i;
		health = h;
		distance = d;
		energyToKill = distance + (health * 5) / 10;
	}

	~Alien()
	{
	}

	void kill()
	{
		health = 0;
	}

	void damage(double damagePercent)
	{
		double amount = damagePercent / health;
		health -= (int)amount;
	}

	string toString() const
	{
		ostringstream oss;
		oss << "Alien ID: " << id
			<< " Health: " << health
			<< " Distance: " << distance
			<< " Energy To Kill: " << energyToKill;

		return oss.str();
	}
};
class defence_system
{
	private:
		static const int ALIEN_TARGETS_TO_POPULATE = 10;
		static const int DEFENCE_SYSTEM_STARTING_ENERGY = 100;
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

