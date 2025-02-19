#include <iostream>
#include "hwexpressions.h"

using std::cout;
using std::cin;

int main()
{
	double meal_amount, tip_rate, tip_amount, tax_amount, total;
	cout << "What did your meal cost? \n";
	cin >> meal_amount;
	tax_amount = get_sales_tax_amount(meal_amount);
	cout << "What percent do you want to tip? (you do not need to type %) \n";
	cin >> tip_rate;
	tip_amount = get_tip_amount(meal_amount, tip_rate);
	total = tip_amount + tax_amount + meal_amount;
	cout << "\n Meal Amount: $" << meal_amount << "\n Tip Amount: $" << tip_amount << "\n Sales Tax: $" << tax_amount << "\n Total: $" << total << "\n";

	return 0;
}
