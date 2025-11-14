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

	/// <summary>
	/// Kill the alien
	/// </summary>
	void kill()
	{
		health = 0;
	}

	/// <summary>
	/// Damage the alien based on a given percentage
	/// </summary>
	/// <param name="damagePercent">Percentage of Damage done to the aliens health</param>
	void damage(double damagePercent)
	{
		double newHealth = health *= (1.0 - damagePercent);
		health = (int)newHealth;

		if (health < 0)
			health = 0;
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
		static const int DEFENCE_SYSTEM_STARTING_ENERGY = 250;
		vector<Alien*> currentTargets;
		int energyRemaining;
		int currentKills;

	public:
		defence_system();
		~defence_system();
		static bool sortTargetsByLowestEnergyToKill(Alien* a, Alien* b);

		/// <summary>
		/// Populate the target list with randomnly generate aliens
		/// </summary>
		void populateTargetsList();

		/// <summary>
		/// Display the aliens in the target vector
		/// </summary>
		void displayTargets();

		/// <summary>
		/// Run the attack simulation for the defence system
		/// </summary>
		void attackTargets();

		/// <summary>
		/// Display the full defence system simulation
		/// </summary>
		void displayDefenceSystem();
};

