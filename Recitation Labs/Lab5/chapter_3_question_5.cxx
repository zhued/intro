#include <iostream>
using namespace std;

void chapter_3_selftest_question_5()
{
	int x = 2;
	cout << "Start\n";
	if (x <= 3)
		if (x != 0)
			cout << "Hello from the second if.\n";
		else
			cout << "Hello from the else.\n";
	cout << "End\n";
}
