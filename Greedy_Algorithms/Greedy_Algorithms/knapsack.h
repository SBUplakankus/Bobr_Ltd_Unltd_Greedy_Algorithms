#pragma once
#include <vector>
#include <sstream>
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
			<< " Value Ratio: " << valueRatio;

		return oss.str();
	}
};

class knapsack
{
	public:
		void InitializeSackOfItems();
		void DisplaySackOfItems();
		double GetHighestWeightTotal(int weightLimit);
		double GetHighestValueTotal(int weightLimit);
		double GetBestValueTotal(int weightLimit);

	private:

		vector<Item*> sackOfItems;
		bool SortByWeight(Item& a, Item& b);
		bool SortByValue(Item& a, Item& b);
		bool SortByBestValue(Item& a, Item& b);

};

