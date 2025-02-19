#include <iostream>
#include "repetition.h"

using std::cout;
using std::cin;

int main() 
{
	while (true){
		int choice;
		cout << "\n1. Factorial\n2. Greatest Common Divisor\n3. Exit\n";
		cin >> choice;
		switch(choice){
			case 1:
				int factorial_input;
				cout << "\nEnter a number to perform a factorial on:\n";
				cin >> factorial_input;
				cout << "\nThe factorial of " << factorial_input << " is " << factorial(factorial_input) << "\n";
				break;
			case 2:
				int gcd_input1, gcd_input2;
				cout << "\nEnter 2 numbers to perform a gcd on:\n";
				cin >> gcd_input1;
				cin >> gcd_input2;
				cout << "\nThe gcd of " << gcd_input1 << " and " << gcd_input2 << " is " << gcd(gcd_input1, gcd_input2) << "\n";
				break;
			case 3:
				int confirmation;
				cout << "\nAre you sure you want to exit?\n1. Yes\n2. No\n";
				cin >> confirmation;
				if (confirmation == 1){
					return 0;
				}
				break;
			default:
				cout << "WRONG NUMBER";
		}
	}

	return 0;
}
