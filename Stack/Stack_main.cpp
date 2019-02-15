#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	cout << "size: ";
	int s;
	cin >> s;
	TStack<int> A = new TStack<int>(s);
	while (n) 
	{
		cout << "1. Put element\n 2. Get element\n 3. Print Stack\n 0. Exit\n";
		cin >> n;
		switch (n)
		{
			case 1:
				int e;
				cout << "Element: ";
				cin >> e;
				A.Put(e);
				break;

			case 2:
				cout << A.Get();
				break;

			case 3:
				A.PrintStack();
				break;

			case 0:
				return 0;

			default: 
				cout << "Wrong command!\n";
				break;
		}
	}
}
