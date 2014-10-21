/*
Name:Edward Zhu

Description: Skeleton code for deranged alphabet lab
	
Notes: http://en.wikipedia.org/wiki/Substitution_cipher#Simple_substitution

Example:
a b c d e f g h i j k l m n o p q r s t u v w x y z 

Please enter a keyword: wolf

a b c d e g h i j k m n p q r s t u v x y z 
w o l f a b c d e g h i j k m n p q r s t u v x y z 

*/

// Include Statements
#include <iostream>			// I/O 
#include <string>			// allows access to string object
#include <cstdlib>			// allows access to EXIT_SUCCESS
#include <list>				// allows access to the STL list
#include <algorithm>		// allows access to the find algorithm

using namespace std;

/*
Description: converts uppercase letters to lowercase letters in a string

In: a string to change 
Out: the new string with all lowercase letters
Side: none
*/
string lowercase(string str);

int main( )
{
	// variable declarations 
	list<char> alphabet;				// the alphabet that will be deranged
	list<char>::iterator list_iter;		// iterator to go through the alphabet
	
	string keyword;							// a string to hold the user keyword
	string::reverse_iterator str_rev_iter;	// reverse iterator to go backward through keyword
	
	// * 1 *
	// put the lowercase letters 'a' through 'z' into the list
	for( unsigned int i = 'a'; i >= 'a' && i <= 'z' ; ++i )
	{
		alphabet.push_back(i);
	}
	
	cout << endl;
	
	// output the list contents showing that all of the letters are there
	for(list_iter = alphabet.begin(); list_iter != alphabet.end(); ++list_iter)
	{
		cout << *list_iter << " ";
	}
	cout << endl << endl;
	
	// ask the user to enter a word
	cout << "Please enter a keyword: ";
	getline(cin, keyword);
	
	cout << endl;
	
	// * 2 *
	// for each character in keyword remove it from the list
	for( unsigned int i = 0; i <= alphabet.size() ; ++i)
	{
		alphabet.erase(find(alphabet.begin(), alphabet.end(), keyword[i]));
	}
	
	// print out the list contents again, which will be the list without 
	//   the keyword characters
	for(list_iter = alphabet.begin(); list_iter != alphabet.end(); ++list_iter)
	{
		cout << *list_iter << " ";
	}
	cout << endl;
	
	// * 3 *
	// Put the keyword with no duplicate chars into the front of the alphabet list
	// Use the string reverse iterator to go through the string characters backward
	//  http://www.cplusplus.com/reference/string/string/rbegin/
	//for( ; ; )
	{
	
		// * 4 *
		// Check if character is already in the alphabet
		// Use the algorithm find( ) function
		//  http://www.cplusplus.com/reference/algorithm/find/
		
		// * 5 *
		// if character not found in the alphabet, add it to alphabet
		//if( )
		{
			
		}
	}
	
	// print out the list contents again, which will be the list with
	//   the keyword on the front
	for(list_iter = alphabet.begin(); list_iter != alphabet.end(); ++list_iter)
	{
		cout << *list_iter << " ";
	}
	cout << endl << endl;
	
	return EXIT_SUCCESS;
}

string lowercase(string str)
{
	for(unsigned int i = 0; i < str.size(); i++)
	{
		if( str.at(i) >= 'A' && str.at(i) <= 'Z' )
		{
			str.at(i) += ('a' - 'A');
		}
	}
	
	return str;
}
