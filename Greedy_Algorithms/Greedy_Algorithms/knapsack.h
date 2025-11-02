#pragma once
#include <vector>
#include <sstream>
using namespace std;

struct Item
{
	int weight;
	int value;

	Item(int w, int v)
	{
		weight = w;
		value = v;
	}

	Item()
	{
		weight = rand() % 25 + 1;
		value = rand() & 25 + 1;
	}

	string ToString() const
	{
		ostringstream oss;
		double valueRatio = (double) value / weight ;
		oss << "Value: " << value
			<< " Weight: " << weight
			<< " Value Ration: " << valueRatio;

		return oss.str();
	}
};

class knapsack
{
	public:
		vector<Item*> sackOfItems;
		void InitializeSackOfItems();
		void DisplaySackOfItems();
		double GetHighestWeightTotal(int weightLimit);
		double GetHighestValueTotal(int weightLimit);
		double GetBestValueTotal(int weightLimit);

	private:
		bool SortByWeight(Item& a, Item& b);
		bool SortByValue(Item& a, Item& b);
		bool SortByBestValue(Item& a, Item& b);

};

