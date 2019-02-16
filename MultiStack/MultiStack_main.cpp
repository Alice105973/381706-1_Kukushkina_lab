#include "MultiStack.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	cout << "size: ";
	int s;
	cin >> s;
	TMStack<int> A (s);
	while (n) 
	{
		cout << "1. Put element\n 2. Get element\n 3. Print MultiStack\n 0. Exit\n";
		cin >> n;
		switch (n)
		{
			case 1:
				int e;
				cout << "Element: ";
				cin >> e;
				cout << "Stack number: ";
				cin >> s;
				A.Set(s, e);
				break;

			case 2:
				cout << "Stack number: ";
				cin >> s;
				cout << A.Get(s);
				break;

			case 3:
				A.PrintMStack();
				break;

			case 0:
				return 0;

			default: 
				cout << "Wrong command!\n";
				break;
		}
	}
}
