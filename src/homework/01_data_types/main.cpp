#include <iostream>
#include "data_types.cpp"

using std::cin;
using std::cout;

int main(){

	int num1;
	int num2;
	cin >> num1;
	cin >> num2;
	int result = multiply_numbers(num1, num2); //FROM data_types.cpp
	cout << "Youre result is " << result << "\n";

	return 0;
}
