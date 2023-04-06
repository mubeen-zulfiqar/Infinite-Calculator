#include"HugeInteger.h"
using namespace std;
int main()
{
	HugeInteger h1;
	cin >> h1;
	cout << h1;
	HugeInteger h2;
	cin >> h2;
	cout << h2;

	cout << "cout << (h == h1) = " << (h1 == h2)<<'\n';
	cout << "cout << (h != h1) = " << (h1 != h2)<<'\n';
	cout << "cout << (h < h1) = " << (h1 < h2) << '\n';
	cout << "cout << (h > h1) = " << (h1 > h2) << '\n';
	cout << "cout << (h <= h1) = " << (h1 <= h2) << '\n';
	cout << "cout << (h >= h1) = " << (h1 >= h2) << '\n';
	
	cout << "Sum of two huge integers is : ";
	HugeInteger h = h1 + h2;
	cout << h;

	cout << "Difference of two huge integers is : ";
	h = h1 - h2;
	cout << h;

	cout << "Product of two huge integers is : ";
	h = h1 * h2;
	cout << h;

	cout << "Division of two huge integers is : ";
	h = h1 / h2;
	cout << h;
	

	cout << "SquareRoot of remainder is : ";
	h.squareRoot();
	cout << h;

	system("pause");
	
}