/*
Name: Edward Zhu
Lecture: MWF 10AM

Description: Most of the despcritions about the assignment is already present in the code.
* I noticed that the encoded and decoded strings are basically the same thing, just a 
* difference in whether to write encoded or decoded, it is semi redundent, 
* but it makes the code look more clean and easy ro read
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string> 
#include <map>

using namespace std;

/*
Description: Prints out the map data with the keys on the first line and the
	mapped values on the second line. Great for debugging!

In: a <char, char> map
Out: none
Side: prints out the keys and values
*/

void printAlphabets( map<char, char> alpha );

/*
Description: changes uppercase letters in a string to lowercase

In: the string to convert
Out: the converted string
Side: none
*/
string lowercase(string text);

/*
Description: removes duplicate characters in the text, leaving only
 	the first instance of each character. 
 	If the text was "helped" the new string would be "helpd"

In: the string to convert
Out: the converted string
Side: none
*/
string removeDuplicateChars( string text );

/*
Description: removes any character that is not in the ranges below
	'a' - 'z' and 'A' - 'Z'

In: the string to convert
Out: the converted string
Side: none
*/
string removeNonLetters( string text );

/*		*** NEED TO COMPLETE ***
Description: takes care of making sure the keyword is valid
	- no special chars
	- no duplicate chars
	- all lowercase letters
	- not larger than the 'a' - 'z' alphabet (26 characters)
	
In: the keyword
Out: the converted keyword
Side: none
*/
string processKeyword( string key );

/*		*** NEED TO COMPLETE ***
Description: Changes each character in string to be shift greater and
	characters that are greater than 'z' will wrap around to beginning
	of alphabet. 
	If character is 'a' and shift is 2, the new character is 'c'
	If character is 'z' and shift is 2, the new character is 'b'

In: the keyword
Out: the shifted keyword
Side: none
*/
string shift( string text, int shift );

/*		*** NEED TO COMPLETE ***
Description: Encrypts a text message based on provided substitution alphabet map.

In: The encrypting alphabet map and the message to encrypt
Out: The encrypted message
Side: none
*/
string encrypt( map<char, char> alpha, string text );

/*		*** NEED TO COMPLETE ***
Description: Decrypts a text message based on provided substitution alphabet map.

In: The decrypting alphabet map and the message to decrypt
Out: The decrypted message
Side: none
*/
string decrypt( map<char, char> alpha, string text );

int main()
{
	map<char, char> cipher_alphabet;	// mapping of char to encoded char value
	int alpha_shift = 0;				// how much to shift alphabet
	int menu_selection = 0;				// what the user selected from the menu
	string keyword; 					// keyword to derange alphabet
	string user_txt;					// text user enters to encrypt / decrypt
	string secret;						// sshhh, it's a secret
	string shift_str;					// string to hold shift value
	string choice_str;					// string to hold menu choice
	
	cout << "\nWelcome to the Deranged Alphabet Shifted Substitution Cipher Program!\n";
	
	while( menu_selection != 3 )
	{
		do{
			cout << "\nMenu:" << endl;
			cout << "1 - Encrypt\n";
			cout << "2 - Decrypt\n";
			cout << "3 - Quit\n";
			cout << "Selection: ";
			getline( cin, choice_str );
			
			// convert choice_str to base 10 number
			//  .c_str() takes a C++ string and returns a C style string
			//  strtol takes a C style string containing only numbers and 
			//    converts it to a long integer that is returned 
			menu_selection = strtol( choice_str.c_str(), NULL, 10 );
		
		} while( menu_selection < 1 || menu_selection > 3 );
		
		if( menu_selection != 3 )
		{
			cout << "\nEnter a text message:\n";
			getline( cin, user_txt );
			
			cout << "\nEnter a keyword: ";
			getline( cin, keyword );
			
			cout << "\nEnter a shift value (0 - 25): ";
			getline( cin, shift_str );
			
			// convert the shift_str value to a base 10 number
			alpha_shift = strtol( shift_str.c_str(), NULL, 10 );
			
			while( alpha_shift > 25 || alpha_shift < 0 )
			{
				cout << "\nIncorrect value entered! Shift can only be 1 - 25!!\n";
				cout << "Enter a shift value (0 - 25): ";
				getline( cin, shift_str );
				
				// convert the shift_str value to a base 10 number
				alpha_shift = strtol( shift_str.c_str(), NULL, 10 );
			}
			
			// ** 1 **
			//	Finish the processKeyword function below main()
			// 	This makes the keyword nice and pretty and valid
			keyword = processKeyword( keyword );
			
			// ** 2 ** 
			//	append the whole 'a' - 'z' alphabet onto the modified keyword
			
			for (int i = int('a'); i<= int('z'); i++)
			{
				keyword += (char)i;
			}
				

			// ** 3 ** 
			//	Remove duplicate characters from keyword that has the alphabet attached
			//    the first character found in keyword will stay and any duplicates
			//    found after will be removed
			//	The keyword has become the deranged alphabet!
	
			keyword = removeDuplicateChars(keyword);
		
			
			// ** 4 ** 
			//	Complete shift function down below main()
			// 	Shift the keyword based on the alpha_shift value entered by user
			keyword = shift( keyword, alpha_shift );
			
		
			cout << "\nMessage Entered:\n";
			cout << user_txt << endl << endl;
			
			if( menu_selection == 1 )
			{
				// ** 5 ** 
				//	Setup encryption alphabet map
				for(int i = 'a'; i <= 'z'; i++)
				{
					cipher_alphabet[char(i)] = keyword[i - 'a'];
				}
				
				cout << "Encoded Message:\n";
				
				// ** 6 ** 
				//	Complete encrypt function down below main()
				secret = encrypt(cipher_alphabet, user_txt);
				cout << secret << endl;
				cout << endl;
			}
			
			if( menu_selection == 2 )
			{
				// ** 7 ** 
				//	Setup decryption alphabet map
				for(unsigned int i = 0; i < keyword.length(); i++)
				{
					cipher_alphabet[keyword[i]] = i + 'a';
				}
				
				cout << "Decoded Message:\n";
				
				// ** 8 ** 
				//	Complete decrypt function down below main()
				secret = decrypt(cipher_alphabet, user_txt);
				cout << secret << endl;
				cout << endl;
			}
		}
	}
	
	cout << "\nGoodbye\n\n";
	
	return EXIT_SUCCESS;
}





















string processKeyword( string key )
{
	// ** 1.1 ** 
	//	Takes care of making sure the keyword is valid
	//    - no special chars
	//    - no duplicate chars
	//    - all lowercase letters
	//   If user enters: He3llO !! W o r l d!!
	//   Processed string is: helowrd
	key = lowercase( key );
	key = removeNonLetters( key );
	key = removeDuplicateChars(  key );
	
			
	// if keyword longer than alphabet size cut off rest
	if( key.size() > 26 )
	{
		key.erase(26);
	}
	
	return key;
}


string shift( string text, int shift )
{
	// ** 4.1 **
	// Go through all of the characters in text and shift them 
	// Check and see if the shifted character is outside 'a' - 'z'
	// If outside fix it so that it wraps around
	//	  With a shift of 2, 'z' would be 'b' and 'y' would be 'a'
	//    With a shift of 4, 'z' would be 'd' and 'w' would be 'a'
	// Else go ahead and shift
	for (string ::iterator iter= text.begin(); iter != text.end(); iter++)
	{
		*iter = (*iter + shift -'a') % ('z' - 'a' + 1) + 'a';
	}
	return text;
}


string encrypt( map<char, char> alpha, string text )
{
	string encoded;		// will hold the encoded message
	
	// ** 6.1 ** 
	//	Ensure that text string only contains 'a' - 'z' characters 
	text = removeNonLetters( text );
	text = lowercase( text );
	
	// ** 6.2 **
	//	Encrypt contents of text and put into encoded string
	
	for ( string ::iterator it = text.begin(); it != text.end(); it++)
	{
		encoded += alpha[*it];
	}	
	

	return encoded;
}

string decrypt( map<char, char> alpha, string text )
{
	string decoded;		// will hold the decoded message
	
	// ** 8.1 ** 
	//	Ensure that text string only contains 'a' - 'z' characters 
	text = removeNonLetters( text );
	text = lowercase( text );
	
	// ** 8.2 ** 
	// Decrypt contents of text and put into decoded string
	
	for ( string ::iterator it = text.begin(); it != text.end(); it++)
	{
		decoded += alpha[*it];
	}	
	
	return decoded;
}























void printAlphabets( map<char, char> alpha )
{
	map<char, char>::iterator iter;	// iterator to traverse a <char, char> map
	
	// print out the keys first, which is the normal alphabet
	cout << left << setw(10) << "Key:";
	for( iter = alpha.begin(); iter != alpha.end(); iter++ )
	{
		cout << iter->first << " ";
	}
	cout << endl;
	
	// print out the mapped values second, which is the deranged alphabet
	cout << left << setw(10) << "Map: ";
	for( iter = alpha.begin(); iter != alpha.end(); iter++ )
	{
		cout << iter->second << " ";
	}
	cout << endl;
}

string lowercase( string text )
{
	for( unsigned int i = 0; i < text.length(); i++ )
	{
		// if a character is in the range 'A' to 'Z' convert to 'a' to 'z'
		if( text.at(i) >= 'A' && text.at(i) <= 'Z' )
		{
			text.at(i) += ('a' - 'A');
		}
	}
	
	return text;
}

string removeDuplicateChars( string text )
{
	size_t found; 				// whether a character is found, npos if not found
	string::iterator s_iter;	// iterator to traverse string
	
	for( s_iter = text.begin(); s_iter != text.end(); s_iter++ )
	{	
		// find character in string
		found = text.find( *s_iter );
		
		// check if there is a duplicate of found character
		while(found != string::npos )
		{
			// check to see if current character is found in string again
			found = text.find( *s_iter, found + 1 );
			
			// if character is found again erase it 
			if( found != string::npos )
			{
				text.erase( found, 1 );
			}
		}
	}
	
	return text;
}

string removeNonLetters( string text )
{
	string::iterator s_iter;	// iterator to traverse string
	
	for( s_iter = text.begin(); s_iter != text.end(); s_iter++ )
	{
		// if character is not in the range 'a' to 'z' erase it
		if( *s_iter < 'A' || (*s_iter > 'Z' && *s_iter < 'a') || *s_iter > 'z' )
		{
			// s_iter is set to element after one erased and this creates
			//  headaches unless s_iter is moved backward one spot
			s_iter = text.erase( s_iter );
			s_iter--;
		}
	}
	
	return text;
}



