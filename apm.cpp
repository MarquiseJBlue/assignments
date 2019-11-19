//////////////////////////////////////////////////////////////////////////
// Author:          MARQUISE BLUE
// Assignment:       Program_03
// Date:             18 November 2019
// Title:            Program 3 -Arbitrary Precision Math
// Semester:         Spring 2019
// Course:           CMPS 1063 
// 
// Files:            apm.cpp, 
//                   DLList.hpp, 
//                   input_data.txt 
//                   output.num
// Description:
//					 this program will use doubly linked lists
//					 to add, subtract and multiply arbitrarily long 	
//					 numbers, then store them in a file.
//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include "DLList.hpp"

using namespace std;

int main()
{
	//infiling and outfiling
	ifstream infile;
	infile.open("input_data.txt");
	ofstream outfile;
	outfile.open("output.num");
	outfile << "Marquise Blue\n" << "Program 3\n"
		    << "Arbitrary Precision Math\n" << endl;

	DoubleyLinked* a = new DoubleyLinked();
	DoubleyLinked* s = new DoubleyLinked();
	DoubleyLinked* p = new DoubleyLinked();
	char op;
	string s1, s2;

	while (infile >> op >> s1 >> s2)
	{
		DoubleyLinked* m = new DoubleyLinked();
		DoubleyLinked* n = new DoubleyLinked();
		for (int i = 0; i < s1.length(); i++) {
			m->FrontSert(s1.at(i) - '0');
		}
		for (int i = 0; i < s2.length(); i++) {
			n->EndSert(s2.at(i) - '0');
		}

		//////////////////////////////////////////////////////Marquise Blue

		cout << "Enter an operator (+, -, *, /): ";
		cin >> op;
		switch (op)
		{
		case '+': a->add(m, n);
			outfile << "Operation 1: Addition\nAnswer:";
			a->PrintResult(outfile); break;
			break;
		case '-':s->sub(m, n);
			outfile << "Operation 2: Subtraction\nAnswer:";
			s->PrintResult(outfile); break;
			break;
		case '*':p->mul(m, n);
			outfile << "Operation 3: Multiplication\nAnswer:";
			p->PrintResult(outfile);
			break;
		}
		delete m;
		delete n;
	}

	infile.close();
	outfile.close();

	return 0;
}