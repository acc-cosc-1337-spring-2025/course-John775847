#include <iostream>
#include "data_types.h"

using std::cin;
using std::cout;

int main(){

	int num1;
	cin >> num1;
	int result = multiply_numbers(num1);
	cout << "Youre result is " << result << "\n";

	return 0;
}
