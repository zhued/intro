//Edward Zhu
//Lab 8 Work

//What to do(written on the whiteboard):
//-add 10 elements
//-print out
//-print out the 5th
//-delete first two
//-print out
//-print out size

#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> grade;

//plugged in 10 elements here
	grade.push_back(5);
	grade.push_back(6);
	grade.push_back(7);
	grade.push_back(8);
	grade.push_back(2);
	grade.push_back(5);
	grade.push_back(2);
	grade.push_back(6);
	grade.push_back(7);
	grade.push_back(3);

//print out all numbers by making a for loop and letting i be less
//than whatever the size of my vector is and adding onto it 
	cout << "Print out all the numbers:" << endl;
	for (unsigned int i = 0; i < grade.size(); ++i)
		cout << " " << grade[i];
	cout << endl;

//printing out the first term is really simple, I just plug 4 into
//the grade vector and cout it
	cout << "Print out the 5th term:" << endl;
	cout << " " << grade[4] << endl;
		
//to delete the first two terms, I used a for loop and erased the
//values what where ever my vector begins to where ever it begins
// +2 values, then I cout it
	cout<< "After deleting the first two terms:" << endl;
	for (unsigned int i = 0; i < 0; i++) grade.push_back(i);
		grade.erase (grade.begin(),grade.begin()+2);
	for (unsigned int i = 0; i < grade.size(); i++)
		cout << " " << grade[i];
	cout << endl;

//printing out the size is like printing out the 5th term, except
//this time you have to make the value of grade.size() an int 	
	cout<< "The size of my vector is now:" << endl;
	cout << " " << (int) grade.size() << endl;
	
	
	cout<< "HURRAY! IT WORKS!" << endl;
	
}
