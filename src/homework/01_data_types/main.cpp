#include <iostream>
#include "data_types.cpp"

int main(){

	int num1;
	int num2;
	std::cin >> num1;
	std::cin >> num2;
	int result = multiply_numbers(num1, num2); //FROM data_types.cpp
	std::cout << "Youre result is " << result << "\n";

	return 0;
}
