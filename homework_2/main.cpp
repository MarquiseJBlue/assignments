/*Marquise Blue
10/09/2019
CMPS 1063- Dr.Griffin
Resizing the array of the  stack gets 80% full. Then I will resize the array
to be 1.5 times larger than it previsously was and reduce the size of my
array if the stack gets down to 20% full.*/

#include <iostream>
#include <fstream>
#include "stdlib.h"

using namespace std;

//Function Prototypes
bool Push(int, int *, int &, int); //Push values onto stack
int Pop(int *, int &); //Removes items from top of stack
void Print(int *, int, ofstream &); //Print out values
bool Empty(int); //Sees if stack is empty
bool Full(int, int); //Sees if stack is full
int checkResize(int, int);
void Enlarge(int *&, int, int &);
void Reduce(int *&, int, int &);


/*
  Push
  Description:
   Adds item to top of stack
  Parms:
   int val : integer size
  Returns:
   bool : true = success
 */
bool Push(int val, int *s1, int & Top, int size)
{
	if (!Full(Top, size))
	{
		Top++;
		s1[Top] = val;
		return true;
	}
	else
	{
		return false;
	}
}


/*															
  Pop
 Description:
  Removes top of stack and returns it
 Params:									               Marquise Blue
  void
 Returns:
  int : item on stack
*/					
int Pop(int *s1, int & Top)
{
	if (!Empty(Top))
	{
		int temp = 0;
		temp = s1[Top];
		Top--;
		return temp;
	}
	else
	{
		cout << "Cannot remove item from empty stack" << endl;
	}
	return 0;
}


/*
  Print
  Description:
   Prints stack for inspection
  Parms:
   void
  Returns:
   void
 */
void Print(int *s1, int Top, ofstream & outfile)
{
	outfile << "Values: ";
	for (int i = Top; i >= 0; i--)
	{
		outfile << s1[i] << " ";
	}
}


/*
  Empty
  Description:
   Is stack empty
  Parms:
   void
  Returns:
   bool : true = empty
 */
bool Empty(int Top)
{
	return Top < 0;										  //Marquise Blue
}


/*
  Full
  Description:
   Is stack full
  Params:
   void
  Returns:
   bool : true = full
 */
bool Full(int Top, int size)
{
	return (Top == size - 1);
}


/*
  CheckResize
  Description:
   checking the size of the array
  Params:
   int
  Returns:
   returns values
 */
int CheckResize(int top, int size)
{
	if (top >= int(size * 0.8 - 1))
	{
		return 1;
	}

	if (top <= int(size * 0.2 - 1))
	{
		return 2;
	}

	return 3;
}


/*
  Enlarge
  Description:
   enlarge the array
  Params:
   void
  Returns:
   bool : true = full
 														   Marquise Blue*/
void Enlarge(int * &s1, int top, int &size)
{
	int new_size = size * 1.5;

	int *s2 = new int[new_size];

	for (int i = 0; i <= top; i++)
	{
		s2[i] = s1[i];
	}

	int *temp = s1;
	s1 = s2;
		s2=temp;
	size = new_size;
	delete[] temp;
}


/*
  Reduce
  Description:
   reducing the array
  Params:
   void
  Returns:
   nothing
 */
void Reduce(int * &s1, int top, int &size)
{
	// Make sure heap has already been enlarged
	if (size > 10)
	{
		int new_size = size / 2;

		int *s2 = new int[new_size];

		for (int i = 0; i < top; i++)
		{
			s2[i] = s1[i];
		}

		int *temp = s1;
		s1 = s2;
		size = new_size;
		delete[] temp;

	}
}


//main function											   Marquise Blue
int main()
{
	// Initialize variables
	int size = 10;
	char operand = '+';
	int num = 0;
	int Top = -1;
	int resize = 0;
	int largest = 10;

	int *s1 = new int[size];
	// Create input and output files
	ifstream inputfile;
	inputfile.open("input_data.txt");

	ofstream outfile;
	outfile.open("stack_out.dat");

	inputfile >> operand;

	// Read until end of file
	while (inputfile.eof() != true)
	{
		inputfile >> num;

		if (operand == '+')
		{
			Push(num, s1, Top, size);
		}

		else if (operand == '-')
		{
			Pop(s1, Top);
		}

		else
		{
			cout << "Not a valid stack operation." << endl;
		}
		resize = checkResize(Top, size);
		if (resize == 1)
		{
			Enlarge(s1, Top, size);

			// Document largest size
			if (size > largest)
				largest = size;
		}

		if (resize == 2)
		{
			Reduce(s1, Top, size);						  //Marquise Blue
		}

		// Read in another operand unless end of file is reached
		if (inputfile.eof() != true)
		{
			inputfile >> operand;
		}
	}
	outfile << "Marquise Blue" << endl;
	outfile << "10/09/2019" << endl;
	outfile << "Homework 2" << endl << endl;
	outfile << "Stack size: " << size << endl;
	outfile << "Largest size: " << largest << endl;
	Print(s1, Top, outfile);

	system("pause");
	return 0;
}
