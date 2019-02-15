#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	cout << "size: ";
	int s;
	cin >> s;
	TVector<int> A(s);
	while (n) 
	{
		cout << "1. Put element\n 2. Get element\n 3. Arithmetic operations\n 4. Print Vector\n 0. Exit\n";
		cin >> n;
		switch (n)
		{
			case 1:
				int e, p;
				cout << "Element: ";
				cin >> e;
				cout << "Position: ";
				cin >> p;
				A[p] = e;
				break;

			case 2:
				int p;
				cout << "Position: ";
				cin >> p;
				cout << "Element: " << A[p] << endl;
				break;

			case 3:
				cout << "1. Scalar addition\n 2. Scalar subtraction\n 3. Scalar multiplication\n 0. Exit\n";
				cin >> n;
				switch (n) {
				case 1:
					int p;
					cout << "Addend number: ";
					cin >> p;
					A = A + p;
					break;
				case 2:
					int p;
					cout << "Subtrahend number: ";
					cin >> p;
					A = A - p;
					break;
				case 3:
					int p;
					cout << "Multiplier number: ";
					cin >> p;
					A = A*p;
					break;
				case 0:
					break;
				default: 
					cout << "Wrong command!\n";
					break;
				}

			case 0:
				return 0;

			default: 
				cout << "Wrong command!\n";
				break;
		}
	}
}