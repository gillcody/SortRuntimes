/*
Authors: Cody Gill (byq195), Peter Nguyen (nat237)
Assignment Number: Project Part 3
File Name: project3.c
Course/Section: CS 2123-004
Due Date: 08 Dec 2019
Instructor: Dr. Ku
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projectHeader.h"

//Function prototypes
int dataTypeMenu(void);
int searchAlgMenu(void);
int dataSizeMenu(void);
void sortFunction(int, int, int);
clock_t clock(void);

int numTrials = 5; //Variable for number of trials

int main()
{
	int dataType; //Variable for data type
	int searchAlg; //Variable for search method
	int arraySize; //Variable for data size

	dataType = dataTypeMenu();
	//printf("\n%d\n", dataType);
	
	searchAlg = searchAlgMenu();
	//printf("\n%d\n", searchAlg);
	
	arraySize = dataSizeMenu();
	//printf("\n%d\n", arraySize);
	
	sortFunction(dataType, arraySize, searchAlg);

}


void sortFunction(int dataType, int arraySize, int searchAlg)
{
	int i, j;
	double timeAvg = 0;
	clock_t time_t;
	double total_t = 0;
	double timeArr[32];
	int *arrayInt;
	int targetInt; //Variable for target integer
        char userStr[MAX_LEN]; //Holds target string
		

	//QuickSort - int
	if (dataType == 1) 
        {
		printf("Enter target integer: ");
	        scanf("%d", &targetInt);

		arrayInt = (int*)malloc(arraySize * sizeof(int));
		for(i = 0; i < arraySize; i++)
                {
  	              arrayInt[i] = randNum();
                }
                quickSort_int(arrayInt, 0, arraySize -1);

		if(searchAlg == 1)
		{

    	   		for (i = 0; i < numTrials; i++)
       			{
        			time_t = clock();
        			linearSearchIterative_int(arrayInt, arraySize, targetInt);
        			time_t = clock()-time_t;
       				total_t = ((double)time_t)/CLOCKS_PER_SEC;
       				if (i == 0)
				{	
					if (linearSearchIterative_int(arrayInt, arraySize, targetInt) == -1)
                                	{
                                		printf("Integer not found.\n");
                               		}
                                	else
                                	{
                                                printf("%d is in position %d of the array.\n", targetInt, linearSearchIterative_int(arrayInt, arraySize, targetInt));
                                	}
				}

        			timeArr[i] = total_t;
        			timeAvg = timeAvg + total_t;
       			}
	
        		timeAvg = timeAvg/numTrials;
        		printf("QuickSort - int%15d%15.6f       ", arraySize,timeAvg);
       			for (i = 0; i < numTrials; i++)
       			{
        			printf("%-15.6f", timeArr[i]);
       			}
			printf("\n");
		}       
		else if (searchAlg == 2)
		{

                        for (i = 0; i < numTrials; i++)
                        {

                                time_t = clock();
                                BinarySearchIterative_int(arrayInt, arraySize, targetInt);
                                time_t = clock()-time_t;
                                total_t = ((double)time_t)/CLOCKS_PER_SEC;
				if (i == 0)
				{
					if (BinarySearchIterative_int(arrayInt, arraySize, targetInt) == -1)
                                	{
                               			printf("Integer not found.\n");
                                	}
                                	else
                                	{
                                                printf("%d is in position %d of the array.\n", targetInt, BinarySearchIterative_int(arrayInt, arraySize, targetInt));
                                	}
				}

                                timeArr[i] = total_t;
                                timeAvg = timeAvg + total_t;
                        }

                        timeAvg = timeAvg/numTrials;
                        printf("QuickSort - int%15d%15.6f       ", arraySize,timeAvg);
                        for (i = 0; i < numTrials; i++)
                        {
                                printf("%-15.6f", timeArr[i]);
                        }
                        printf("\n");
                }
		free (arrayInt);

	}
	else if (dataType == 2)
	{
		char arrayStr[arraySize][MAX_LEN];
	        FILE *fileIn;
        	char buffer[MAX_LEN];
        	fileIn = fopen("last_name.txt", "r");

		if (fileIn != NULL)
                {
                	for(i = 0; i < arraySize; i++)
                        {
                        	fgets(arrayStr[i], MAX_LEN, fileIn);
			}
                }         
                quickSort_str(arrayStr, 0, arraySize);


		printf("Enter target string: ");
		fgets(userStr, MAX_LEN, stdin);               
		if(searchAlg == 1)
                {
                        for (i = 0; i < numTrials; i++)
                        {

                                time_t = clock();
                                linearSearchIterative_str(arrayStr, arraySize, userStr);
                                time_t = clock()-time_t;
                                total_t = ((double)time_t)/CLOCKS_PER_SEC;

				if (i == 0)
				{
					if (linearSearchIterative_str(arrayStr, arraySize, userStr) == -1)
                              		{
                    	        		printf("String not found.\n");
                                	}
                                	else
                                	{
                          	              printf("%s is in position %d of the array.\n", userStr, linearSearchIterative_str(arrayStr, arraySize, userStr));
                                	}
				}
					

                                timeArr[i] = total_t;
                                timeAvg = timeAvg + total_t;
                        }

                        timeAvg = timeAvg/numTrials;
                        printf("QuickSort - str%15d%15.6f       ", arraySize,timeAvg);
                        for (i = 0; i < numTrials; i++)
                        {
                                printf("%-15.6f", timeArr[i]);
                        }
                        printf("\n");
                }
		if(searchAlg == 2)
                {
                        for (i = 0; i < numTrials; i++)
                        {
                                time_t = clock();
                                BinarySearchIterative_str(arrayStr, arraySize, userStr);
                                time_t = clock()-time_t;
                                total_t = ((double)time_t)/CLOCKS_PER_SEC;

				if (i == 0)
                                {
                                        if (BinarySearchIterative_str(arrayStr, arraySize, userStr) == -1)
                                        {
                                                printf("String not found.\n");
                                        }
                                        else
                                        {
                                              printf("%s is in position %d of the array.\n", userStr, BinarySearchIterative_str(arrayStr, arraySize, userStr));
                                        }
                                }


                                timeArr[i] = total_t;
                                timeAvg = timeAvg + total_t;
                        }

                        timeAvg = timeAvg/numTrials;
                        printf("QuickSort - str%15d%15.6f       ", arraySize,timeAvg);
                        for (i = 0; i < numTrials; i++)
                        {
                                printf("%-15.6f", timeArr[i]);
                        }
                        printf("\n");
                }


	}


}

//Function to choose data type
int dataTypeMenu(void)
{
		int x=0;
	do {
		printf("Select a data type to search: \n\n");
		printf("1. Integers\n");
		printf("2. Strings\n");
		printf("3. Exit Program\n\n");
		printf("Enter a number from 1-3: ");
		scanf("%d", &x);
		printf("\n");
		(void) getchar();
		
		switch (x)
		{
		case 1:
			{
				printf("Selected Integers\n\n");
				x = 1;
				return x;
				break;
			}
		case 2:
			{
				printf("Selected Strings\n\n");
				x = 2;
				return x;
				break;
			}
		case 3:
			{
				printf("Selected '3'\n\n");
				printf("EXITING PROGRAM\n");
				exit(0);
			}
		default:
			{
				printf("Must enter a number from 1-3!\n\n");
				x=0;
			}
		}
	} while (x==0);
}

//Function to choose search method
int searchAlgMenu(void)
{
		int x=0;
	do {
		printf("Select a method of Searching: \n\n");
		printf("1. Linear Search\n");
		printf("2. Binary Search\n");
		printf("3. Exit Program\n\n");
		printf("Enter a number from 1-3: ");
		scanf("%d", &x);
		printf("\n");
		(void) getchar();
		
		switch (x)
		{
		case 1:
			{
				printf("Selected Linear Search\n\n");
				break;
			}
		case 2:
			{
				printf("Selected Binary Search\n\n");
				break;
			}
		case 3:
			{
				printf("Selected '3'\n\n");
				printf("EXITING PROGRAM\n");
				exit(0);
			}
		default:
			{
				printf("Must enter a number from 1-3!\n\n");
				x=0;
			}
		}
	} while (x==0);
}

//Function to choose data size
int dataSizeMenu(void)
{
		int x=0, y=0;
	do {
		printf("Select a data size to search from: \n\n");
		printf("1. 1,000\n");
		printf("2. 10,000\n");
		printf("3. 20,000\n");
		printf("4. 30,000\n");
		printf("5. 40,000\n");
		printf("6. 50,000\n");
		printf("7. 60,000\n");
		printf("8. 75,000\n");
		printf("9. Exit Program\n\n");
		printf("Enter a number from 1-9: ");
		scanf("%d", &x);
		printf("\n");
		(void) getchar();
		
		switch (x)
		{
		case 1:
			{
				printf("Selected 1,000\n\n");
				y = 1000;
				return (y);
				break;
			}
		case 2:
			{
				printf("Selected 10,000\n\n");
				y=10000;
				return (y);
				break;
			}
		case 3:
			{
				printf("Selected 20,000\n\n");
				y=20000;
				return (y);
				break;
			}
		case 4:
			{
				printf("Selected 30,000\n\n");
				y=30000;
				return (y);
				break;
			}
		case 5:
			{
				printf("Selected 40,000\n\n");
				y=40000;
				return (y);
				break;
			}
		case 6:
			{
				printf("Selected 50,000\n\n");
				y=50000;
				return (y);
				break;
			}
		case 7:
			{
				printf("Selected 60,000\n\n");
				y=60000;
				return (y);
				break;
			}
		case 8:
			{
				printf("Selected 75,000\n\n");
				y=75000;
				return (y);
				break;
			}
		case 9:
			{
				printf("Selected '9'\n\n");
				printf("EXITING PROGRAM\n");
				exit(0);
			}
		default:
			{
				printf("Must enter a number from 1-9!\n\n");
				x=0;
			}
		}
	} while (x==0);
}
