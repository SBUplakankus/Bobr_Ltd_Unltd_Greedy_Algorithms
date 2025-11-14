#pragma once
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

struct Item
{
	int id;
	int weight;
	int value;
	double valueRatio;

	Item(int i, int w, int v)
	{
		id = i;
		weight = w;
		value = v;
		valueRatio = (double)value / weight;
	}

	Item(int i)
	{
		id = i;
		weight = rand() % 20 + 1;
		value = rand() % 20 + 1;
		valueRatio = (double)value / weight;
	}

	~Item()
	{
	}

	string ToString() const
	{
		ostringstream oss;
		oss << "Item ID: " << id
			<< " Value: " << value
			<< " Weight: " << weight
			<< " Value Ratio: " << setprecision(2) << valueRatio;

		return oss.str();
	}
};

class knapsack
{
	private:
		static const int NUM_ITEMS = 10;
		static const int TEST_WEIGHT_LIMIT = 25;
		vector<Item*> sackOfItems;
		static bool SortByWeight(Item* a, Item* b);
		static bool SortByValue(Item* a, Item* b);
		static bool SortByBestValue(Item* a, Item* b);
	public:
		knapsack();
		~knapsack();

		/**
		 * @brief Fill the sack with randomnly generated items
		 */
		void InitializeSackOfItems();

		/**
		 * @brief Display the sack of items in console
		 */
		void DisplaySackOfItems();

		/**
		 * @brief Run the greedy algorithm to maximize total weight
		 * @param weightLimit Maximum weight allowed in the sack
		 */
		void GetHighestWeightTotal(int weightLimit);

		/**
		 * @brief Run the greedy algorithm to maximize total value
		 * @param weightLimit Maximum weight allowed in the sack
		 */
		void GetHighestValueTotal(int weightLimit);

		/**
		 * @brief Run the greedy algorithm to maximize value to weight ratio
		 * @param weightLimit Maximum weight allowed in the sack
		 */
		void GetBestValueTotal(int weightLimit);

		/**
		 * @brief Display the results of the greedy algorithms
		 */
		void DisplaySackValues();
};

