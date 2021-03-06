#include "pch.h"
#include <iostream>
#include"LinkedQueue.h"

//A function that prints queue contents
template <typename T>
void PrintQueue(LinkedQueue<T> Q)
{
	T K;
	cout << "\nQueue contents: ";
	while (Q.dequeue(K))
		cout << K << " ";
	cout << endl;
}


template<typename T>
void RemoveDuplicates(LinkedQueue<T>& q) {
	LinkedQueue<T> tmp_q, final_q;
	T curVal, t;
	while (q.dequeue(curVal)) {
		while (q.dequeue(t)) {
			if (t != curVal) tmp_q.enqueue(t);
		}
		while (tmp_q.dequeue(t)) q.enqueue(t);
		final_q.enqueue(curVal);
	}
	while (final_q.dequeue(t)) q.enqueue(t);
}


int main()
{
	// ==>   NOTE:
	// A runtime error occurs when your run this code
	// What is the problem and how to solve it ?????

	//Declare a queue of integers named "queue1"
	LinkedQueue<int> queue1;
	int x, n;

	cout << "\nEnter no. of values to enqueue:";
	cin >> n;

	//Test the 1st stack by pushing n values then poping
	cout << "Filling queue 1:" << endl;
	cout << "Enqueuing " << n << " values:" << endl;

	cout << "Please Enter the " << n << " values to enqueue in queue1 :";
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		queue1.enqueue(x); //pushing x to stack2
	}

	PrintQueue(queue1);
	RemoveDuplicates(queue1);
	PrintQueue(queue1);
}