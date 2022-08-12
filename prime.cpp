#include<iostream>

using namespace std;

int main()
{
	//Initialize the variables to long long int (64 bits) to account for extremely large numbers in the user input
	long long int upper = 0;
	long long int lower = 0;
	// Initialize the current and divisor variables to be used in the loops
	long long int current = 0;
	long long int divisor = 0;
	//Initialize i to zero
	long long int i = 0;
	//Initiliaze the prime counter, which will be used to count the number of prime divisors in our loop
	long long int prime = 0;
	// Cout statement for user input of lower and upper values
	cout << "Enter a range of numbers to factorize. Enter lower bound and upper bound separated by a space: ";
	cin >> lower >> upper;
	//PSEUDOCODE FROM HINT 6: 
		// Set lower and upper, the lower and upper bounds of numbers to factorize.
		//For each i from lower to upper...
		//Set current to i and start with a divisor of divisor = 2. Until divisor
		//exceeds i / 2 or current equals 1...
		//If divisor divides evenly into current, set current = current / divisor
		//and print divisor with an ‘x’(or without an ‘x’ if current is 1).
		//Otherwise, replace divisor by the smallest odd number bigger than
		//divisor.
		//If divisor has exceeded i / 2, the number is prime.

	//Create for loop for each i from lower to upper
	for (i = lower; i <= upper; i++)
	{
		//set current to i and start with divisor = 2, which is our lowest possible prime divisor
		current = i;
		divisor = 2;
		//Initilize the prime counter to zero within the loop
		prime = 0;
		//Print the numbers from lower to upper (each i) with colon next to
		cout << "\n" << i << ": ";
		//While loop will be used for the condition "until divisor exceeds i/2 or current equals 1"
		while (divisor <= i / 2 && current > 1)
		{
			//Use if else statement for te conditions of the current and divisor
			//IF the divisor divides evenly into the input, then the current is equal to the current/divisor
			if (current % divisor == 0)
			{
				current = current / divisor;
				//Use another nested if else statement to account for the x's in between the numbers
				//This ensures that no extra x's will be printed with the prime divisors
				//If there are no more prime divisors counted, then print the divisor.
				//Any other conditions will have an x after it
				if (prime == 0)
				{
					cout << divisor;
				}
				else
				{
					cout << " x " << divisor;
				}
				prime++;
			}
			//If the divisor is equal to two, then divisor++ will continue to count the next prime divisor in the conditions of the loop
			else if (divisor == 2)
			{
				divisor++;
			}
			//Any other condition, +=2 will count the next odd number, and the loop will decide whether or not the number is prime
			//This just replaces the divisor with next odd number, and if the divisor ha exceed i/2, the number is prime
			else
			{
				divisor += 2;
			}

		}
		// If else statement will be used for the prime! and unit! conditions for prime numbers in user input and unit! for 1.
		//Prime == 0 and for current not equal to 1 will print 'prime!' next to all the prime numbers not equal to 1
		if (prime == 0 && current != 1)
		{
			cout << "prime!";
		}
		// This condition prints 'unit!' next to the 1, which is needed because 1 is a prime number and will have prime!
		// printed next to it if it is not made.
		else if (prime == 0 && current == 1)
		{
			cout << "unit!";
		}
	}
	return 0;
}

