/*Marquise Blue
CMPS 1063-- Dr. Griffin
*/
#include <iostream>
using namespace std;

struct Animal
{
	string name;
	double weight;
	double scary;
	Animal()
	{
		name = "";
		weight = 0.0;
		scary = 0.0;
	}
	Animal(string _name, double _weight, double _scary)
	{
		name = _name;
		weight = _weight;
		scary = _scary;
	}
};
struct Node
{ //typical node setup for a list.
	Animal * data; //simple integer data.
	Node* Next;
	Node()
	{ //default constructor
		Next = NULL;
	}
	Node(Animal * a) 
	{ //overloaded constructor
		data = a;
		Next = NULL;
	}
};
/**
* List Queue
*
* List Based Queue
*
*/
class ListQueue
{
private:
	Node* Front; //front of the queue (where we remove from)
	Node* Rear; //rear of the queue (where we add to)
public:
	ListQueue(); //construct
	void Push(Animal *); //add animals to rear
	Animal * Pop(); //remove from front
	void Print();//print for debugging
	bool Empty();//if queue is empty(can't remove from empty queue)
	void PrintPointers();// added for lecture purposes
	Node* GetFront();// added for lecture purposes
};
/**
* ListQueue
* Purpose:
* Constructs our queue
* Params:
* void
* Returns:
* void
*/
ListQueue::ListQueue() 
{
	Front = Rear = NULL;
}
/**
* Push
* Purpose:
* Adds item to rear of queue
* Params:
* Animal ani : item to be added
* Returns:
* void
*/
void ListQueue::Push(Animal * a) 
{
	Node* temp = new Node(a); //allocate new memory
	if (Front == NULL) 
	{ //if list is empty
		Front = Rear = temp; //point everyone to it
	}
	else 
	{
		Rear->Next = temp; //otherwise link last node to new one
		Rear = temp; //then point Rear to it.
	}
}
/**

* Pop
* Purpose:
*Removes animal from front of queue
* Params :
*void
* Returns :
*animal : front item
*/
Animal * ListQueue::Pop()
{
	Animal * temp = Front->data; //get front data temporarily
	Node* T = Front; //point to the front temporarily
	Front = Front->Next; //move front to next item
	delete T; //delete the old front
	if (!Front)
	{ //if front is NULL make rear NULL as well
		Rear = NULL; //because if front is NULL list is empty!
	}
	return temp; // return front integer
}
/**
* Print
* Purpose:
* Prints items in queue for debugging
* Params:
* void
* Returns:
* void
*/
void ListQueue::Print() 
{
	Node* temp = Front;
	//modify to read the member variables in each animal
	while (temp)
	{
		cout << temp->data;
		if (temp->Next) 
		{
			cout << "->";
		}
		temp = temp->Next;
	}
	cout << endl;
}
/**
* Empty
* Purpose:
* Checks for empty queue. Cant remove from empty queue!
* Params:
* void
* Returns:

* bool: true == empty
*/
bool ListQueue::Empty() 
{
	return Front == NULL;
}
/**
* PrintPointers
* Purpose:
* Prints front and rear values for lecture purposes
* Params:
* void
* Returns:
* void
*/
void ListQueue::PrintPointers() 
{
	cout << "Front = " << Front << endl;
	cout << "Rear = "  << Rear << endl;
}
/**
* GetFront
* Purpose:
* Returns the front node, for lecture purposes
* Params:
* void
* Returns:
* void
*/
Node* ListQueue::GetFront() 
{
	return Front;
}