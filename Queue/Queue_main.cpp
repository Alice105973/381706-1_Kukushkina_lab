#include "Queue.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	cout << "size: ";
	int s;
	cin >> s;
	TQueue<int> A(s);
	break;
	while (n) 
	{
		cout << "1. Put element\n 2. Get element\n 3. Print Queue\n 0. Exit\n";
		cin >> n;
		switch (n)
		{
			case 1:
				int e;
				cout << "Element: ";
				cin >> e;
				A.Enqueue(e);
				break;

			case 2:
				cout << A.Dequeue();
				break;

			case 3:
				A.Print();
				break;

			case 0:
				return 0;

			default: 
				cout << "Wrong command!\n";
				break;
		}
	}
}
