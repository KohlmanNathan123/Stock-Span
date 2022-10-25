#include <iostream>
#include <cstdlib>
#include <ctime>
int main(){
	//Declare n and sentry for checking if n is in the right range
	bool nWrong = true;
	int n;

	//Declares srand with seed at time(0) to get new numbers each run
	srand(int(time(0)));
	while(nWrong){
		std::cout << "Enter a number n for the number of elements: ";
		std::cin >> n;
		if((n >= 1) && (n <= 100)){
			nWrong = false;
		}else{
			std::cout << "Not in range" << std::endl;
		}
	}

	//Declare arrays for numbers and span
	int array[n];
	int span[n];

	//Assigns a random number between 1 and 200 in array
	for(int i = 0; i < n; i++){
		//range of 1 - 200
		int num = (rand() % 200) + 1;
		array[i] = num;
	}

	//For loop from 0 to n-1 for indexes of arrays
	for(int x = 0; x < n; x++){
		//sets current number to find span for
		int currNum = array[x];

		//sentry for while loop
		bool keepGoing = true;

		//current span measures span for current number
		//dec measures how many indecies the loop is behind currNum
		int currSpan = 1;
		int dec = 1;
		while(keepGoing){
			//If x = 0, span is 1
			if(x != 0){
				//number being measured less than or greater than currNum
				int prevNum = array[x - dec];

				//If the current number is greater than prevNum, increase span and move to 1 number further back
				if(currNum > prevNum){
					currSpan += 1;
					dec += 1;
				}
				//If the previous number is equal or greater, break from the loop
				else{
					break;
				}
			}else{
				keepGoing = false;
			}
		}
		//Set span for current number
		span[x] = currSpan;
	}

	//Prints initial array of numbers and array of spans
	std::cout << "Array of values: (";
	for(int z = 0; z < n - 1; z++){
		std::cout << array[z] << ", ";
	}
	std::cout << array[n-1] << ")" << std::endl;
	std::cout << "Span of each number: (";
	for(int y = 0; y < n - 1; y++){
		std::cout << span[y] << ", ";
	}
	std::cout << span[n-1] << ")" << std::endl;
}
