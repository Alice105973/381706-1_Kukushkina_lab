#include "Queue.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	TQueue<int> A = new TQueue();
	while (n) 
	{
		ñout << "1. Create new Queue\n 2. Put element\n 3. Get element\n 4. Print Queue\n 0. Exit\n";
		cin >> n;
		switch (n)
		{
			case 1:
				cout << "size: ";
				int s;
				cin >> s;
				~A;
				A = new TQueue(s);
				break;

			case 2:
				int e;
				cout << "Element: ";
				cin >> e;
				A.Enqueue(e);
				break;

			case 3:
				cout << A.Dequeue();
				break;

			case 4:
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
