/*--PROGRAM DESCRIPTION:
The following is a lottery program that contains various amounts of user interaction
The program will begin with a basic printed output introduction to the user, explaining the basics of the program.
A Main Menu will then be displayed with 6 options which are the following:
-Option 1: The user is able to input 6 numbers that will be stored in an array by use of a function call.
-Option 2: A function is call to print out the user inputs
-Option 3: This is will call a function that will sort the numbers the user entered using the Insertion Algorithm.
-Option 4: This will reveal the the user what prize they will recieve from their selected numbers.
-Option 5: A function is called to show how many times each inputted number has been inputted during the running of the program.
-Option 6: A function call will made that will increment a variable which will put an end to the programs loop and end the program
--Author: Robert Vaughan
--Date: 16/02/2016 - 03/03/2016
--IDE: Bloodshell DEV C++ 5.11
--Complier: GCC
--OS: Windows 10
*/

#include <stdio.h>

#define SIZE 42
#define USER_NUM 6
#define TOTAL 7

//Prototypes
int readNumbers(int*, int*, int*, int*);//Read in user input
void showNumbers(int*);//Prints users inputs
void sortNumbers(int*, int*);//Sorts user numbers
void compareNumbers(int*, int*);//Compares user numbers
void freqNumbers(int*, int*);//DIsplays user frequency
void endProgram(int*);//Ends program

main()
{
	//Declarations
	int win_numbers[TOTAL]={1, 3, 5, 7, 9, 11, 42};//Variable that stores winning lotto numbers.
	int input_num[USER_NUM]={0};//Variable that will store user input.
	int frequency[SIZE + 1]={0};//Variable that will store the frequency of user inputs.
	int access=0;//Variable that will prevent users from using various program options.
	int menu_input='0';//Variable that will store a users input at the Main Menu.
	int lock=0;//Variable that keeps the loop of the program running
	int sort = 0;//Chefck if inputs are sorted
	
	//Printed output to welcome user. Will be displayed once.
	printf("This is PC based Lotto game\n");
	printf("\nBelow is your menu to navigate through the game.\n");
	printf("Good luck!\n\n");
	
	while (lock != 1)
	{
		//The following list of print functions display a main menu
		printf("	>>MAIN MENU<<\n");
		printf("	Enter 1 to choose your 6 lotto numbers.\n");
		printf("	Enter 2 to reveal your lotto numbers that you entered.\n");
		printf("	Enter 3 to sort your numbers in order.\n");
		printf("	Enter 4 to compare your chosen numbers with the winning numbers\n");
		printf("	Enter 5 to display the frequency of the numbers entered each time.\n");
		printf("	Enter 6 to end the game.\n");
		
		//User input
		printf("\nPlease choose you an option.\n");
		scanf("%d", &menu_input);
		fflush(stdin);
		
		switch (menu_input)
		{
			case 1:
			{
				//Call to read in users numbers
				readNumbers(input_num, frequency, &access, &sort);
				break;
			}//end case
			
			case 2:
			{
				//Condition to check if a user has entered valid inputs
				if (access > 0)
				{
					//Call to print users numbers
					showNumbers(input_num);
				}//end if
				else
				{
					//Error checking
					printf("\nYou must enter your numbers first!\n\n");
				}//end else
				
				break;
			}//end case
		
			case 3:
			{
				//Checks if the users numbers are already sorted
				if (sort > 0 && access > 0)
				{
					printf("\nYour numbers are already sorted.\n\n");
					break;
				}//end if
				
				//Condition to check if a user has entered valid inputs
				if (access > 0 && sort == 0)
				{
					//Call to sort users answers using Bubble Sort
					sortNumbers(input_num, &sort);
				}//end if
				else
				{
					//Error checking
					printf("\nYou must enter your numbers first!\n\n");
				}//end else
				
				break;
			}//end case
		
			case 4:
			{
				//Condition to check if a user has entered valid inputs
				if (access > 0)
				{
					//Call to compare users numbers with hard-coded winning numbers
					compareNumbers(input_num, win_numbers);
				}//end if
				else
				{
					//Error checking
					printf("\nYou must enter your numbers first!\n\n");
				}//end else
				
				break;
			}//end case
			
			case 5:
			{
				//Condition to check if a user has entered valid inputs
				if (access > 0)
				{
					//Call to reveal the frequency of inputted numbers during programs running
					freqNumbers(input_num, frequency);
				}//end if
				else
				{
					//Error checking
					printf("\nYou must enter your numbers first!\n\n");
				}//end else
				
				break;
			}//end case

			case 6:
			{
				//Call to return a value from a function that is great than zero.
				//This will end the programs loop and end the program.
				endProgram(&lock);
				break;
			}//end case
			
			//The default case will be entered in any user error is entered
			default:
			{
				printf("\nYou did not enter a numeric value within the given range.\n");
				printf("\nPlease enter a valid numeric value given (1 - 6).\n\n");
				break;
			}//end default
		}//end switch
	}//end while
}//end main

/*Implement readNumbers() to read in the users 6 numbers
If a user enters any invalid characters, appropiate error checking will
follow. One the user has entered 6 numbers, their numbers will be saved and stored
along with the frequency of those numbers being incremented.
*/

int readNumbers(int* temp_array, int* freq_copy, int* entry, int* sort_check)
{
	//Declarations
	int i = 0;
	int j = 0;
	
	//Resets the check if a user sorted their numbers
	*(sort_check) = 0;
	
	printf("\nPlease enter your 6 numbers. After each number, click enter to store it.\n");
	printf("Your numbers must be in the range of 1 to 42.\n");
	
	//Loop to enter in all of the users numbers
	for (i = 0; i < USER_NUM; i++)
	{	
		printf("%d: ", (i + 1));
		scanf("%d", (temp_array + i));
		fflush(stdin);
		
		//Checks if the users input is valid
		if ((*(temp_array + i)) > SIZE || (*(temp_array + i)) < 1 || (*(temp_array + i)) == 0)
		{
			printf("\nYou have entered an invalid input.\n");
			printf("\nPlease re-enter number %d\n", (i + 1));
			
			//Restores element to zero within the array
			*(temp_array + i) = 0;
			
			i = i - 1;
		}//end if
		
		//Checks if the user has not already entered in a number
		for (j = 0; j < i; j++)
		{
			if ( (*(temp_array + i)) == (*(temp_array + (j))) )
			{
				printf("\nYou have entered a number you already entered.\n");
				printf("\nPlease re-enter number %d\n", (i + 1));
				
				//Restores element to zero within the array
				*(temp_array + i) = 0;
				
				j = i;
				i = i - 1;
			}//end if
			
		}//end for
		
	}//end for
	
	//Loop to increment frequency of the values
	for (i = 0; i < USER_NUM; i++)
	{	
		*(freq_copy + *(temp_array + i)) = *(freq_copy + *(temp_array + i)) + 1;
	}//end for
	
	//Allows a user to access more options
	(*entry)++;
		
	printf("\nYour numbers are entered and saved!\n\n");	
	
}//end readNumbers

/*Implement showNumbers() to print the users entered numbers.
If no numbers are entered. A user will be asked to enter their 
numbers first to enter this option.
*/

void showNumbers(int* show_array)
{
	//Declarations
	int i = 0;
	
	printf("\nHere are your numbers\n");

	//Condition to check each if the numbers have been entered
	if (*(show_array + i) != 0)
	{
		for (i = 0; i < USER_NUM; i++)
		{	
			printf("\nNumber %d: %d\n", (i + 1), *(show_array + i));
		}//end for
		
		printf("\n");
		
	}//end if
	else
	{
		printf("\nYou must enter your numbers first!\n");
	}//end else
	
}//end void

/*Implement sortNumbers() to use the Insertion Algorithm to
sort the users entered numbers in order. Insertion is utilised
for a user will likely enter their 6 numbers in order already.
Insertion Sort is known to be the best algorithm to deal with midly 
sorted elements within an array. Below is a visual based example on how
the algorithm operates
124356 -- Checks 2 aginst 1
124356 -- Checks 4 aginst 2
124456 -- Checks 3 aginst 4 and finds that 3 is smaller and is swapped over
123456 -- 3 is stored in a variable and checked against 2. Since 2 is smaller 3
is placed in the element next to it.
*/

void sortNumbers(int* sort_array, int* sort_check)
{
	//Declarations
	int i = 0;
	int j = 0;
	int current = 0;//To store numbers
	
	//Increments variable to make user aware the numbers are sorted
	(*(sort_check))++;
	
	//Looks at each number and checks if any element is greater than the current number
	for (i = 1; i < USER_NUM; i++)
	{
		current = *(sort_array + i);
		j = i;
		
		//A loop that will check if any number is greater that the number in the scope
		while (*(sort_array + (j - 1)) > current && j != 0)
		{
			*(sort_array + j) = *(sort_array + (j - 1));
			j = (j - 1);
		}//end while
		
		*(sort_array + j) = current;
	}//end for
	
	printf("\nYour numbers are sorted!\n\n");
}//end sortNumbers

/*Implement compareNumbers() to compare the users entered numbers
with the hard-coded winning numbers. If the user has entered a certain 
amount of correct numbers, they will win a prize depending on how many numbers 
they entered correcetly.
*/

void compareNumbers(int* input_array, int* win_array)
{
	//Declarations
	int i = 0;
	int j = 0;
	int count = 0;//Count for matching
	int extra = 0;//Count for bonus ball
	
	//Nested loops to compare each number in both arrays
	for (i = 0; i < USER_NUM; i++)
	{
		for (j = 0; j < USER_NUM; j++)
		{
			if (*(input_array + j) == *(win_array + i))
			{
				count++;
			}//end if
			
			//Bonus number condition
			if (*(input_array + j) == *(win_array + USER_NUM))
			{
				extra++;
			}//end if
		}//end for
	}//end for
	
	//A switch statement that deals with every possibly outcome for a users entry
	//with the use of various cases.
	switch (count)
	{
		case 3:
		{
			//Bonus Ball Check
			if (extra > 0)
			{	
				printf("\nMatch %d + Bonus: Cinema ticket!\a\n\n", count);
			}//end if
			else
			{
				printf("\nYou sadly have not won any prizes!\n");
				printf("You matched %d number/s and did not match the bonus ball.\n\n", count);
			}//end else
		
		break;
		}//end case
		
		case 4:
		{
			//Bonus Ball Check
			if (extra > 0)
			{
				printf("\nMatch %d + Bonus: Weekend Away!\a\n\n", count);
				break;
			}//end if
			else
			{
				printf("\nMatch %d: Night Out!\a\n\n", count);
			}//end else
		
		break;
		}//end case
		
		case 5:
		{
			//Bonus Ball Check
			if (extra > 0)
			{
				printf("\nMatch %d + Bonus: New Car!\a\n\n", count);
			}//end if
			else
			{
				printf("\nMatch %d: Holiday!\a\n\n", count);
			}//end else
		
		break;
		}//end case
		
		case 6:
		{
			printf("\nMatch %d: ***Jackpot!***\a\n\n", count);
			break;
		}//end case
		
		default:
		{
			printf("\nYou sadly have not won any prizes!\n");
			printf("You matched %d number/s", count);
			
			//Condition to check if the user entered the bonus number
			if (extra > 0)
			{
				printf(" and the bonus ball\n\n");
			}//end if
			else
			{
				printf(".\n\n");
			}//end else
			
			break;
		}//end default
	}//end switch
}//end compareNumbers()

/*Implement freqNumbers() to measure how many times each number has been
entered while the program is in operation
*/

void freqNumbers(int* copy_array, int* freq_copy)
{
	//Declarations
	int i = 0;
	int count = 0;//Counter
	
	//Loops through every element within the frequency array
	for (i = 0; i < SIZE + 1; i++)
	{
		//Condition to check if a element in the array was an entered number
		if ((*(freq_copy + i)) > 0)
		{
			count++;
			printf("\n%d: Number %d has been selected %d time/s.\n", count, i, *(freq_copy + i));
		}//end if
	}//end for
	
	//Line space
	printf("\n");
}//end freqNumbers()

/*Implement endProgram() that will increment a value 
which will end the programs loop.
*/

void endProgram(int* copy_lock)
{
	printf("\n***SHUTTING DOWN***\n");
	
	//Increments variable to end the program
	(*copy_lock)++;
}//end endProgram()
