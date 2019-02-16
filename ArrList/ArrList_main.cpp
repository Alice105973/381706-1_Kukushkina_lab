#include "ArrList.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	cout << "size: ";
	int s;
	cin >> s;
	TArrList<int> A(s);
	while (n) 
	{
		cout << "1. Put element\n 2. Get element\n 3. Print List\n 0. Exit\n";
		cin >> n;
		int e;
		switch (n)
		{
			case 1:
				cout << "PUT:\n 1. Start\n 2. End\n 3. Another position\n 0. Exit\n";
				cin >> n;
				switch (n) {
				case 1:
					cout << "Element: ";
					cin >> e;
					A.PutEnd(e);
					break;
				case 2:
					cout << "Element: ";
					cin >> e;
					A.PutStart(e);
					break;
				case 3:
					int p;
					cout << "Position: ";
					cin >> p;
					cout << "Element: ";
					cin >> e;
					A.Put(p, e);
					break;
				case 0:
					break;
				default:
					cout << "Wrong command!\n";
					break;
				}
				break;

			case 2:
			cout << "GET:\n 1. Start\n 2. End\n 3. Another position\n 0. Exit\n";
			cin >> n;
			switch (n) {
				case 1:
					A.GetEnd();
					break;
				case 2:
					A.GetStart();
					break;
				case 3:
					int p;
					cout << "Position: ";
					cin >> p;
					A.Get(p);
					break;
				case 0:
					break;
				default:
					cout << "Wrong command!\n";
					break;
				}
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
