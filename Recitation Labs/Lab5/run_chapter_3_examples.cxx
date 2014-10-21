#include <iostream>

using namespace std;
// please see p.131 of the text for the switch statement code I adapted here

// we need to tell the compiler that these functions exist
void chapter_3_selftest_question_5();
void chapter_3_selftest_question_6();
void chapter_3_selftest_question_25();
void chapter_3_selftest_question_26();

int main()
{
	char choice;
	
	// This do-while loop is a new kind of loop.
	// It runs at least once and then checks if it should continue.
	// In this case, it runs until the user types 0 (zero) to quit
	do 
	{
		cout << "\n" // Savitch puts an endl here but it's mixing endl and "\n", which is yucky
			 << "Choose 'A' to run chapter 3 self-test example 5\n"
			 << "Choose 'B' to run chapter 3 self-test example 5\n"
			 << "Choose 'C' to run chapter 3 self-test example 5\n"
			 << "Choose 'D' to run chapter 3 self-test example 5\n"
			 << "Choose '0' to quit running examples\n"
			 << "Enter your choice and hit Return: ";
		cin >> choice;
		
		switch(choice)
		{
			case 'A':
				chapter_3_selftest_question_5();
				break;
			case 'B':
				chapter_3_selftest_question_6();
				break;
			case 'C':
				chapter_3_selftest_question_25();
				break;
			case 'D':
				chapter_3_selftest_question_26();
				break;
			case '0':
				cout << "End of Program\n";
				break;
			default:
				cout << "Not a valid choice.\n"
					 << "Choose again\n";
		}
	} while (choice != '0');
	
	return 0;
}	
			 
			 
