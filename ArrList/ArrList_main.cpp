#include "ArrList.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	TArrList<int> = new TArrList();
	while (n) 
	{
		ñout << "1. Create new List\n 2. Put element\n 3. Get element\n 4. Print List\n 0. Exit\n";
		cin >> n;
		switch (n)
		{
			case 1:
				cout << "size: ";
				int s;
				cin >> s;
				~A;
				A = new TArrList(s);
				break;

			case 2:
				cout << "PUT:\n 1. Start\n 2. End\n 3. Another position\n 0. Exit\n";
				cin >> n;
				switch (n) {
				case 1:
					int e;
					cout << "Element: ";
					cin >> e;
					A.PutEnd(e);
					break;
				case 2:
					int e;
					cout << "Element: ";
					cin >> e;
					A.PutStart(e);
					break;
				case 3:
					int e, p;
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

				case 3:
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
