#include <iostream>
#include <string>
#include "func.h"

using std::string;
using std::cout;
using std::cin;

int main(){
	while(true){
		string dna_for_gc;
		string dna_for_complement;

		int choice;
		cout << "\n1. Get GC Content\n2. Get DNA Complement\n3. Exit\n";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "\nEnter a string for gc calculation (ALL CAPS)\n";
				cin >> dna_for_gc;
				cout << "\nThe gc content is " << get_gc_content(dna_for_gc) << "\n";
				break;
			case 2:
				cout << "\nEnter a string for gc calculation (ALL CAPS)\n";
				cin >> dna_for_complement;
				cout << "\nThe complement is " << get_dna_complement(dna_for_complement) << "\n";
				break;
			case 3:
				return 0;
			default:
				cout << "WRONG NUMBER";
		}
	}

	return 0;
}
