#pragma once
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

struct Item
{
	int weight;
	int value;
	double valueRatio;

	Item(int w, int v)
	{
		weight = w;
		value = v;
		valueRatio = (double)value / weight;
	}

	Item()
	{
		weight = rand() % 30 + 1;
		value = rand() % 30 + 1;
		valueRatio = (double)value / weight;
	}

	string ToString() const
	{
		ostringstream oss;
		oss << "Value: " << value
			<< " Weight: " << weight
			<< " Value Ratio: " << setprecision(2) << valueRatio;

		return oss.str();
	}
};

class knapsack
{
	private:

		vector<Item*> sackOfItems;
		static bool SortByWeight(Item* a, Item* b);
		static bool SortByValue(Item* a, Item* b);
		static bool SortByBestValue(Item* a, Item* b);
	public:
		void InitializeSackOfItems();
		void DisplaySackOfItems();
		double GetHighestWeightTotal(int weightLimit);
		double GetHighestValueTotal(int weightLimit);
		double GetBestValueTotal(int weightLimit);

	

};

