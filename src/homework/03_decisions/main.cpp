#include <iostream>
#include "decisions.h"

using std::cin;
using std::cout;

int main() 
{
	int choice;
	cout << "\tMain Menu\n\n1. Letter grade using if\n2. Letter grade using switch\n3. exit\n";
	cin >> choice;
	if (choice == 1 || choice == 2){
		int grade;
		cout << "\nEnter grade number:\n";
		cin >> grade;
		if (grade <= 100 && grade > 0){
			switch(choice){
				case 1:
					cout << "\nYour letter grade is " << get_letter_grade_using_if(grade) << "\n";
					break;
				case 2:
					cout << "\nYour letter grade is " << get_letter_grade_using_switch(grade) << "\n";
					break;
			}
		} else {
			cout << "\n\n\tERROR OUT OF BOUNDS\n\n";
		}
	}
	return 0;
}
