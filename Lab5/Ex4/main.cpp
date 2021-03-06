#include "pch.h"
#include <iostream>
#include "ArrayStack.h"
#include "LinkedQueue.h"
using namespace std;

// A function to print stack contents
//as the function shoud operate on a class template, the function itself should be a function template as well
template <typename T>
void PrintStack(ArrayStack<T> S)
{

	cout << endl << "Printing stack contents: ";

	T x;
	while (S.pop(x))
		cout << x << " ";

	cout << endl;
}


//A function that takes a ArrayStack<T> S and returns its reverse (without affecting the orignal stack)
template <typename T>
void ReverseMe(ArrayStack<T>& S)
{
	LinkedQueue<T> aux_q;	//First creat a stack 
	T tmp;
	while (S.pop(tmp)) aux_q.enqueue(tmp);
	while (aux_q.dequeue(tmp))S.push(tmp);
}


int main()

{
	ArrayStack<int> stack1;

	int i, x;

	//Test the 1st stack by pushing 1, 2, 3, 4 and 5 then popping them.
	cout << "Testing stack 1:" << endl;
	cout << "Pushing 5 values into stack 1:" << endl;

	//Reading From the user 5 integer values
	cout << "Please Enter the 5 values to push in stack1 :";
	for (i = 0; i < 5; i++)
	{
		cin >> x;
		stack1.push(x); //pushing x to stack1
	}

	cout << "\nstack1 contents\n";
	PrintStack(stack1);

	ReverseMe(stack1);

	cout << "\nAfter ReverseMe...\nstack1 contents\n";
	PrintStack(stack1);

	cout << endl;
	return 0;


}
