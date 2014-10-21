//Edward Zhu
//Recitation = Wednesday 9AM

//To Do list:
//1-Create new map, name and grade
//2-Add five elements
//3-Print out all elements
//4-Print out all the names having grade 100


#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
//I made 5 elements here under map grades
	map<string, int> grades;
	grades["StudentA"] = 100;
	grades["StudentB"] = 96;
	grades["StudentC"] = 52;
	grades["StudentD"] = 82;
	grades["StudentE"] = 100;
	
//I make a gradescopy as a iterator version of grades
	map<string, int>::iterator gradescopy;
	gradescopy=grades.begin();

//Use a for loop to print out all the scores one by one
	cout << "My students got these grades:\n";
	for ( gradescopy=grades.begin() ; gradescopy != grades.end(); gradescopy++ )
		cout << (*gradescopy).first << " = " << (*gradescopy).second << endl;
		cout << endl;

//use another for loop, but this time I added an if statement to separate,
//and only print out the students that got 100s
	cout << "Who got 100% on the test?" << endl;
	for ( gradescopy=grades.begin() ; gradescopy != grades.end(); gradescopy++ )
		if ( (*gradescopy).second == 100)
	{
			cout << (*gradescopy).first << " got a 100%! Yeah! " << endl;
	}
	
}
