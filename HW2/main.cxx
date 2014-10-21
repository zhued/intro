//Edward Zhu
//CSCI 1300 - 010


//1. Given answer is choosen randomly, the probability of winning is 0.4979
//2. When the answer is set to zero, running the iteration 10000 times
//		gave a winning probability of 0.3305
//3. When the answer is set to one, running the iteration 10000 times
//		gave a winning probability of 0.6678

#include<iostream>
#include<cstdlib>
#include<ctime>



using namespace std;

//Generates one of the door numbers of: 1,2,3 
int randGenerator(int n)
{
	return (rand() % (n)) + 1;
	// return an answer
}

//Generates a yes or No answer to the question of if you want to change your door choice.
// Assume that Yes == 1 and No == 0 in this case. 
int yesNoGenerator(int n)
{
	return rand() % n;
	// return an answer
}

int main()
{

	//Number of correct door guesses by the user, initialized to 0
	
	int correctDoorCount=0;
	
	//Number of iterations for the simualtion
	
	int iter=0;
	
	//Number of the door with the prize (either 1, 2, or 3)
	
	//int prizeDoor;
	
	//Number of the door the player chooses at the start (either 1, 2, or 3)
	
	//int userChoice;
	
	//Number of the door Monty opens, which has no prize (either 1, 2, or 3)
	
	//int consolationDoor;
	
	//Number of the door that could be chosen after the consolationDoor is revealed:
	
	//int alternativeDoor;
	
	//Randomly generated yes/no (1/0) answer to the question of whether the player switches doors 
	
	//int answer;
	
	//Percentage success in choosing the prize over all the simulations
	// this is the probability of winning
	
	//double result;
	
	// Make sure we get a different series of random values every time.
	// This command initializes the random number generation with a value taken
	// from your computer's current time, which should always be different

//I commented most of the ints out because I name and use them later on in the code

	srand(time(NULL));	
	
	//1. Prompt the user for the number of iterations that simulation needs to be run
//I ask the user how many games he or she wants to play
	cout << "How many iterations or games do you want to play? ";
	cin >> iter;
	cout << "The Number of iterations that the simulation needs to run is: "<< iter <<endl<< endl;




	//2. Do the simulation for iter times by filling in this for statement.
	for (int i = 0; i < iter; i++)
	{		
		//3. Initialize prizeDoor, userChoice, and consolationDoor randomly
		int prizeDoor = randGenerator(3);
		
		int userChoice= randGenerator(3);
	
		int consolationDoor=randGenerator(2);
		if (consolationDoor== prizeDoor || consolationDoor == userChoice)
			consolationDoor++;
		
		//4. Check to make sure that consolationDoor is a valid value,
		// given prizeDoor and userChoice
		
		cout << "prize Door: " << prizeDoor<<endl; 
		cout << "user Choice: " << userChoice<<endl; 
		cout << "consolation Door: " << consolationDoor<<endl; 

		//5. Choose an alternative door that we could open, given userChoice and consolationDoor
//use a boolean value to figure out the alternative door
		bool alternativeDoor= rand()%2 ==0;
			

		//6. Choose a Yes or No answer to the question: "Do you want to change your door choice?"
		
//The three 'int answer's I used to figure out the percentages

		int answer=yesNoGenerator(2);
		//int answer=1;
		//int answer=0;
		
		
		//There are 3 ways this variable may be set.
		// Either, the user randomly chooses Yes (1) to change the door or No (0) to keep her current door.
		// Or, the user always chooses Yes (1) to change the door
		// Or, the user always chooses No (1) to keep her door.
		// Begin by setting this to a random choice between 0 (No) and 1 (Yes).  
		// When you think you have the random choice answer, see what happens when 
		// you instead simulate the problem with an answer of 0 (never switch doors)
		// and an answer of 1 (always switch doors).

		//7. If the user keeps her door choice and it is the correct one, then increment the numeber of correct doors chosen

		//If the user asks her door choice to be changed:
		
//if loop for when the answer is 1, meaning you change to the alternative door
		if (answer == 1)
		{
			if (!alternativeDoor && (userChoice==prizeDoor))
				{++correctDoorCount;
				}
			else if (alternativeDoor && (userChoice != prizeDoor))
				{++correctDoorCount;
				}
			// 8. change the user choice to the alternative door
			// 9. If the alternative door is the prize door, then increment the number of correct doors chosen
		else
		{
			if (userChoice == prizeDoor)
				{++correctDoorCount;
				}
		}
		}
//if loop for when the answer is zero, meaning that the user doesn't change his or her initial choice
		if (answer ==0)
		{
				if (userChoice == prizeDoor)
				{++correctDoorCount;
				}
				
		}
		cout << "alternative Door: " << alternativeDoor <<endl;
		cout << endl << endl;
		
	}//end of the for loop for the simulation
	
	cout<<"Number of correct guesses: "<<correctDoorCount<<endl<<endl;

	//10. Calculate the probability of correct guesses: 
	
	double result=((double)correctDoorCount)/iter;
	cout <<"The probablity of choosing the right door is: "<< result <<endl<< endl;

	return 0;
	}//end of main

//12. Generate random numbers of (0,1,2) + 1 to get door numbers 1, 2 and 3

//I defined int randGenerator and yesnoGenerator at the very beggining of the code, thus i commented out the ones below

//int randGenerator(int n)
//{
//	return (rand() % (n)) + 1;
	// return an answer
//}

//13. Generate 0 or 1 randomly:
//  0 : No = Don't change my door choice
//  1 : Yes = Change my door choice to Alternative door
//int yesNoGenerator(int n)
//{
//	return rand() % n;
	// return an answer
//
