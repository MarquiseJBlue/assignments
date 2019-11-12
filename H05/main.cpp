*////////////////////////////////////////////////////////////////////////////////
//
// Author:           MARQUISE BLUE
// Assignment:       HOMEWORK_5
// Date:             10 November 2019
// Title:            Homework 5- Fixing a loop
// Semester:         Spring 2018
// Course:           CMPS 1063 
// 
// Files:            main.cpp
// Description:
//                   have a list of animals that need to be sorted out
//					 alphabetically and fixing a loop to see why it is not
//					 sorting correctly the last three words on the linked list
//
/////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <fstream> 

using namespace std;


/**
 * Node
 *
 * Description:
 *      creating a Node
 *
 * Params:
 *      no params
 * Returns:
 *      nothing to return
 */

struct Node
{
	string word;
	Node* Next;
	Node(string w)
	{
		word = w;
		Next = NULL;
	}
};
/**
 * Class Dictionary
 *
 * Description:
 *     making a class for the dictionary to input a string
 *
 * Params:
 *      string input : input a list of letters into the file and making it all
 *       lowercase
 * Returns:
 *      returning the input
 */
class Dictionary
{
private:
	Node* Start;

	string LowerCase(string input)
	{
		for (int i = 0; i < input.length(); i++)
		{
			if ((int)input[i] < 96)
			{
				input[i] += 32;
			}
		}
		return input;
	}


public:

	Dictionary() {
		Start = NULL;
	}
	/**
	 * Add
	 *
	 * Description:
	 *     adding the words to the linked list
	 *
	 * Params:
	 *      string word: a string of a type of animal
	 *
	 * Returns:
	 *      nothing returning
	 */
	void Add(string word) {

		word = LowerCase(word);
		// create new memory
		Node* temp = new Node(word);

		// if list is empty hook in new Node
		if (Start == NULL)
		{
			Start = temp;
		}
		else {
			// get ready to walk the list
			Node* traverse = Start;
			while (traverse->Next != NULL)
			{
				// walks the list
				traverse = traverse->Next;
			}
			// now at proper place to link in new memory
			traverse->Next = temp;
		}
	}
	/**
	 * Remove
	 *
	 * Description:
	 *     removing the string to the new list
	 *
	 * Params:
	 *      string key
	 *
	 * Returns:
	 *      returning temp
	 */
	string Remove(string key)
	{
		string temp = "";

		if (!Start) {
			return "";
		}
		else
		{
			Node* cptr = Start;
			Node* prev = Start;
			while (cptr && cptr->word != key)
			{
				prev = cptr;
				cptr = cptr->Next;
			}
			// if cptr then we found the word
			if (cptr)
			{
				temp = cptr->word;
				prev->Next = cptr->Next;
				delete cptr;
			}
			else {
				// no word, return empty
				temp = "";
			}
			return temp;
		}
		return temp;
	}

	/**
	 * ReOrder
	 *
	 * Description:
	 *      reordering the linked list of animals from A to Z
	 *
	 * Params:
	 *      no params
	 *
	 * Returns:
	 *      not returning anything
	 */
	void ReOrder() {
		// pointers for new list
		Node* NewList = NULL;
		Node* Tail = NULL;

		int i = 0;

		while (Start != NULL) {

			// helper pointers to manipulate lists
			Node* Ptr = Start;
			Node* Min = Start;
			Node* Prev = Start;
			Node* MinPrev = Start;


			// find one minimum word in old list
			while (Ptr != NULL) {
				if (Ptr->word < Min->word) {
					MinPrev = Prev;
					Min = Ptr;
				}

				Prev = Ptr;
				Ptr = Ptr->Next;
			}
			//end finding one word in old list

			// add one word to new list

			if (!NewList) {
				NewList = Min;
			}
			else {
				Tail->Next = Min;
			}

			Tail = Min;
			if (Min == Start) {
				Start = Start->Next;
			}
			else {
				MinPrev->Next = Min->Next;
			}

			Min->Next = NULL;

			i++;
			if (i >= 8) {
				break;

			}
			// adding one word to new list

			//  Node* Temptemptmemp = NewList;

			// while(Temptemptmemp){
			//   cout<<Temptemptmemp->word<<" ";
			//   Temptemptmemp = Temptemptmemp->Next;
			//  }
			//  cout<<endl;
		}

		Start = NewList;


	}
	/**
   * Print
   *
   * Description:
   *      printing the old list and new list to the screeen
   *
   * Params:
   *      no parameters
   * Returns:
   *      Nothing to return
   */
	void Print()
	{
		Node* temp = Start;
		while (temp)
		{
			cout << temp->word;
			if (temp->Next)
			{
				cout << "->";
			}
			temp = temp->Next;
		}
		cout << endl;
	}
};
/////////////////////////////////////////////////////
/**
 * Main Function
 *
 * Description:
 *      adding words to a list and couting strings to the output screen
 *
 * Params:
 *      No Params
 *
 * Returns:
 *     No returns
 */
int main()
{
	Dictionary W;
	ifstream fin("dictionary.txt");
	string word;


	W.Add("Ant");
	W.Add("Dog");
	W.Add("Aaron");
	W.Add("Aardvark");
	W.Add("Cow");
	W.Add("Rabbit");

	cout << "Marquise Blue\n";
	cout << "Homework 5\n";
	cout << "Fixing a broken loop\n\n";
	cout << "Before it is sorted:\n";
	W.Print();
	cout << endl;
	W.ReOrder();
	cout << "After it is sorted:\n";
	W.Print();

}
