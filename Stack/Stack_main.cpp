#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	TStack<int> A = new TStack();
	while (n) 
	{
		cout << "1. Create new Stack\n 2. Put element\n 3. Get element\n 4. Print Stack\n 0. Exit\n";
		cin >> n;
		switch (n)
		{
			case 1:
				cout << "size: ";
				int s;
				cin >> s;
				~A;
				A = new TStack(s);
				break;

			case 2:
				int e;
				cout << "Element: ";
				cin >> e;
				A.Put(e);
				break;

			case 3:
				cout << A.Get();
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
