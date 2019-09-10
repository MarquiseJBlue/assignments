#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class Student
{
private:
	string firstname;
	string lastname;
	int numGrades;
	int grades[10];

public:
	// Function Prototypes
	Student();
	Student(string, string, int, int[]);
	// Accessor Functions

	string getfirstname()
	{
		return firstname;
	}
	string getlastname()
	{
		return lastname;
	}
	int getnumGrades()
	{
		return numGrades;
	}

	void showGrades(int);
};

// Default Constructor

Student::Student()
{
	firstname = "";
	lastname = "";
	numGrades = 0;
	for (int i = 0; i < 10; i++)
	{
		grades[i] = 0;
	}
}
// Constructor

Student::Student(string first, string last, int count, int new_grades[])
{
	firstname = first;
	lastname = last;
	numGrades = count;
	for (int i = 0; i < numGrades; i++)
	{
		grades[i] = new_grades[i];
	}
}
// This function will print out the grades of a student when called

void Student::showGrades(int numGrades)
{
	for (int i = 0; i < numGrades; i++)
	{
		cout << grades[i] << " ";

	}

	cout << endl;
}
// Function Prototypes
void loadClassList(vector<Student> &);
void printClassList(Student, int);

int main()
{
	// Create a vector to hold the students

	vector<Student> ClassList;



	// Load the data from the input file into the vector

	loadClassList(ClassList);



	// Used to print out student number

	int counter = 1;



	// Print out a list of the students and their grades

	for (int i = 0; i < ClassList.size(); i++)

	{

		printClassList(ClassList[i], counter);

		counter++;

	}



	// Pause the screen so user can read output

	system("pause");

	return 0;

}



// This function loads the data from an input file into 

// the program and then stores it into the vector of objects

void loadClassList(vector<Student> & list)

{

	// Create an ifstream object and open the file

	ifstream inputfile;

	inputfile.open("input.txt");



	// Initialize variables

	string first;

	string last;

	int grades[20];

	int count = 0;



	inputfile >> first;



	// Store data into the vector until end of file is reached

	while (!inputfile.eof())

	{

		inputfile >> last;

		inputfile >> count;

		for (int i = 0; i < count; i++)

		{

			inputfile >> grades[i];

		}



		Student NewStudent = Student(first, last, count, grades);

		list.push_back(NewStudent);

		inputfile >> first;

	}





}



// This function prints out each student along with their grades

void printClassList(Student stu, int counter)
{
	int numGrades = 0;
	// Header for table

	if (counter == 1)

	{
		cout << "Students" << endl;
		cout << "=======================================\n";
	}
	// Make a string that will hold a student's full name

	string first = stu.getfirstname();
	string last = stu.getlastname();
	string fullname = first + " " + last;

	// Print out the student's name 

	cout << left << counter << ". " << setw(18) << fullname << ": ";
	numGrades = stu.getnumGrades();
	stu.showGrades(numGrades);
}