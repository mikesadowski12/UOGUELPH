//NAME: Mike Sadowski
//STUDENT NUMBER: 0864810
//DATE: September 12th, 2013


//INCLUDE STATEMENTS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//CONSTANTS
#define magicBMInum 703
#define MAX 100

//PROTOTYPES
float CalculateBMI(int height, int weight);
void printBMIinfo(float BMI, int height, int weight);
int checkUserInput(char *userInput, int *number);

void main(void)
{
	int weight = 0;
	int height = 0;
	float bmi = 0.0;
	int checkError = 0; 
	char userInputHeight[MAX] = "\0";
	char userInputWeight[MAX] = "\0";
	char loopCheck = "Y";

	system("clear");

	do
	{
		//Grab user input for height, keep looping until all characters typed in are numbers
		do
		{
			printf("Please enter a height: ");
			//scanf("%f", &height);
			fgets (userInputHeight , sizeof(userInputHeight) , stdin);
			checkError = checkUserInput(userInputHeight, &height);
		}while (checkError == 1);

		//Grab user input for weight, keep looping until all characters typed in are numbers
		do
		{
			printf("\nPlease enter a weight: ");
			//scanf("%f", &weight);	
			fgets (userInputWeight , sizeof(userInputWeight) , stdin);
			checkError = checkUserInput(userInputHeight, &weight);	
		}while (checkError == 1);

		bmi = CalculateBMI(height, weight);//Calculate BMI
		printBMIinfo(bmi, height, weight);//Print user's bmi, height and weight
		
		//ask user if they wish to keep looping through the program
		printf("Would you like to keep looping? [Y/N]: ");
		loopCheck = getchar();

	}while(loopCheck == "Y" || loopCheck == "y");
}



//NAME: CalculateBMI
//DESCRIPTION: Calculate the users Body Mass Index based on their height and weight
//PARAMETERS: Two floats representing height and weight
//RETURNS: New BMI as a float
float CalculateBMI(int height, int weight)
{
	float newBMI = 0.0;
	
	//BMI = ( Weight in Pounds / ( Height in inches x Height in inches ) ) x 703
	newBMI = ((weight / (height * height)) * magicBMInum);

	return newBMI;
}



//NAME: printBMIinfo
//DESCRIPTION: Print the users Body Mass Index, their height and weight
//PARAMETERS: Three floats representing BMI, height and weight
//RETURNS: NONE
void printBMIinfo(float BMI, int height, int weight)
{
	system("clear");
	printf("Height: %d\n", height);
	printf("Weight: %d\n", weight);
	printf("BMI:    %.4f\n", BMI);
	printf("\n\n");
}



//NAME: checkUserInput
//DESCRIPTION: Check user inputted string for non number characters
//PARAMETERS: A string, and a pointer to a number to set if the string contains all numbers
//RETURNS: 0 for no errors, 1 for error (if string had a non-number character in it)
int checkUserInput(char *userInput, int *number)
{
	int x = 0;
	int digitFlag = 0;//flag to detect if a non number was typed in
	char Input[MAX] = "\0";
	strcpy(Input, userInput);

	for (x = 0; x < sizeof(Input); x++)
	{
 		if (isdigit(*(Input[x])) == 0)//if 0 returned, character was not a number..
		{
			digitFlag++;//increase flag by 1
			break;//exit loop if non-number character was found
		}
	}	
	
	if (digitFlag == 0)
	{	
		*number = atoi (Input);//set the number since string contained all numbers
		return 0;//return no error
	}
	else
	{
		return 1;//return error
	}
}



