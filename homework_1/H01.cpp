/*Marquise Blue
CMPS 1063 9/26/2019
Inputting data of students into the program, and printing it onto the screen

*/
#include <iostream>
#include <string>
#include< fstream>
#include <vector>
#include <iomanip>

using namespace std;

class Student
{
private:
	string fname;
	string lname;
	int numGrades;
	int grades[10];



public:
	//function prototypes
	Student();
	Student(string, string, int, int[]);

	string getfname()
	{
		return fname;
	}
	string getlname()
	{
		return lname;
	}
	int getnumGrades() {
		return numGrades;
	}
	void showGrades(int, ofstream&);
};

Student::Student()
{
	fname = " ";
	lname = " ";
	numGrades = 0;
	for (int i = 0; i < 10; i++)
	{
		grades[i] = 0;
	}
}

//constructor
Student::Student(string first, string last, int count, int newGrades[])
{
	fname = first;
	lname = last;
	numGrades = count;

	for (int i = 0; i < numGrades; i++)
	{
		grades[i] = newGrades[i];
	}

}

void Student::showGrades(int numGrades, ofstream& outfile)
{
	for (int i = 0; i < numGrades; i++)
	{
		outfile << grades[i] << " ";
	}
}

void loadClassList(vector<Student>&);

void printClassList(Student, int, ofstream&);

int main()
{
	ofstream outfile;
	outfile.open("output.txt");

	//Creating a vector to hold the students
	vector<Student>(classList);

	//Load the data from the input file into the vector
	loadClassList(classList);
	int counter = 1;

	//Print out a list of the studetns and their grades
	for (int i = 0; i < classList.size(); i++)
	{
		printClassList(classList[i], counter, outfile);
		counter++;
	}

	//pause the screen so user can read output
	system("pause");
	return 0;
}

void loadClassList(vector<Student>&list)
{
	//creating a ifstream object to open the file
	ifstream infile;
	infile.open("input_data.txt");

	//initializing the variables
	string first; string last;
	int grades[10];
	int count = 0;
	infile >> first;
	
	//strore data into the vecor until end of file is reached
	while (!infile.eof())
	{
		infile >> last >> count;
		for (int i = 0; i < count; i++)
		{
			infile >> grades[i];
		}
		Student newStudent = Student(first, last, count, grades);
		list.push_back(newStudent);
		infile >> first;
	}
}

//printing off the students and their grades
void printClassList(Student stu, int counter, ofstream& outfile)
{
	int numGrades = 0;
	if (counter == 1)
	{
		outfile << "Students" << endl;
		outfile << "===================================" << endl;
	}

	//make a string that will hold a students full name
	string first = stu.getfname();
	string last = stu.getlname();

	outfile << left << counter << " . " << setw(18) << first << " " << last << ": ";
	numGrades = stu.getnumGrades();
	stu.showGrades(numGrades, outfile);
	outfile << endl;
}
