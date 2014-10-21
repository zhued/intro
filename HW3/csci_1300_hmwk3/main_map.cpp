/*
Name:Edward Zhu

Lecture:MWF 10AM

Description: I will follow each number and describe what I did.
1.Simple thing that clears the string
2.I made it so that iter would look through the map of user_text as the key if there were any duplicates
3.Used an If-else statement, if no dups, then the data value =1, if there are dups, then data value++
4.Simple code to slide everything to the left
5.Simple code for presicion of 2 after decimal
6.I check if there were any Tabs, and added them to the map, and did the same with spaces
7.Again, simple code to slide everything to the left
8.Here is where I run the checks in part 6, and also print out the key of the maps and then the data
9.I combined 9 and 10, set everything to the right and made everything look pretty and neat
	then showpoint to show decimal, and then made it so float values are in fixed-point notation
	and then found the percentages by using a double(so there isn't int division) and multiplied by 100
10.See above(9)
*/

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;


int main( )
{
	map <char, int> letters;		// a map with char key and int data
	map <char, int>::iterator iter;	// iterator for the map
	string user_text;				// a user_text entered by the user
	string answer;					// whether the user wants to re-run the program
	iter=letters.begin();
	
	do
	{
				
		// 1. map must be cleared for each iteration of do-while 
		letters.clear();
		
		// get the user_text the user enters
		cout << endl << "Please enter some text and press enter: ";
		getline( cin, user_text );
		
		
		// iterate through the user_text entered
		for(unsigned int i = 0; i < user_text.size(); ++i)
		{	
			
			// 2. check to see if letter is already in the user_text
			iter = letters.find(user_text[i]);
			
			// 3. if the letter is not already in the map add it and make the count 1
			//    else the letter already exists and the count needs to increase by 1
			
			if(iter == letters.end())
			{
                letters[user_text[i]] = 1;
			}
			else
			{
				(*iter).second++;
			}
			
		}
		cout<<endl;
		// print out the total letters in the user_text
		cout << "Total letters in the user text = " << user_text.size() << endl << endl;		
		
		
		// Construct a nicely formatted table
		//  Column 1 is a list of the characters in the user_text
		//  Column 2 is the number of times each letter occurs in the user_text
		//  Column 3 is the percent each letter occurs compared to total user_text characters
		//		the decimal point is fixed and only two decimal places are shown
		//	In the chart, a tab is listed as <TAB> and space as <SPACE>
		// 
		// References to help with formatting:
		//	 http://www.cplusplus.com/reference/iostream/ios_base/flags/
		//   http://www.cplusplus.com/reference/iostream/ios_base/precision/
		//	 http://www.cplusplus.com/reference/iostream/ios_base/setf/
		//   http://www.cplusplus.com/reference/iostream/manipulators/setw/
		//	 http://www.cplusplus.com/reference/iostream/manipulators/showpoint/
		
		
		
		// 4. set justification left
		cout.width(10); cout << left;
		
		// 5. set to show two decimal places of precision for decimal numbers
		cout.precision(2);
		
		// display table header info
		cout << setw( 10 ) << "Char" << setw( 10 ) << "Count" << setw( 10 ) << "Percent" << endl;
		cout << "----------------------------------" << endl;
		
		// 6. iterate through the contents in the map using an iterator
		
		
		for(iter = letters.begin(); iter != letters.end(); iter++)
		{
			// 7. set justification left
			cout.width(10);cout << left;
			
			
			// 8. display characters and character count in their columns
			if((*iter).first == '\t')		// check for tab character
			{
				cout << "<TAB>" << setw( 10 ) << (*iter).second;

			}
			else if( (*iter).first == ' ' )	// check for space character
			{
				cout << "<Space>"<< setw( 10 ) << (*iter).second;
				// print out <SPACE> here
			}
			else							// all other cases
			{
				cout << (*iter).first << setw( 10 ) << (*iter).second;
				// print out any other characters here
			}
			
			// 9. set justification right
			// 10. display the percentage in fixed decimal format where decimal point is always shown
			//	 you will need to use showpoint and fixed
			
			cout << right << setw(6) << showpoint << fixed <<((double)(*iter).second/user_text.size())*100 << "%"<< endl;
		}
		
		
		// ask the user if they would like to enter another user_text
		cout << endl << "Would you like to enter more text (y/n): ";
		getline( cin, answer );
		
		// if user presses enter key without inputting any text prompt user again
		while(answer.empty())
		{
			cout << endl << "Invalid Answer - Would you like to enter more text (y/n): ";
			getline( cin, answer );
		}
		
	} while ( answer.at(0) == 'y' || answer.at(0) == 'Y' );
	
	return EXIT_SUCCESS;
}
