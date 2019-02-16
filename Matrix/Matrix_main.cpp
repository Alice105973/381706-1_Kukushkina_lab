#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	cout << "size: ";
	int s;
	cin >> s;
	int e, i, j;
	TMatrix<int> A(s);
	while (n) 
	{
		cout << "1. Put element\n 2. Get element\n 3. Print Matrix\n 0. Exit\n";
		cin >> n;
		switch (n)
		{
			case 1:
				cout << "Element: ";
				cin >> e;
				cout << "Position: ";
				cin >> i >> j;
				A[i][j] = e;
				break;

			case 2:
				cout << "Position: ";
				cin >> i >> j;
				cout << "Element: " << A[i][j] << endl;
				break;

			case 3:
				cout << A;
				break;

			case 0:
				return 0;

			default: 
				cout << "Wrong command!\n";
				break;
		}
	}
}
