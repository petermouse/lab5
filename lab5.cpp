#include <iostream>
#include "HugeInt.h"
using namespace std;

int main()
{
	HugeInt x;
	HugeInt y(28825252);
	HugeInt z("314159265358979323846");
	HugeInt result;
	cin >> x;
	result = x + y;
	cout << x << " + " << y << " = " << result << endl;
	result = z - x;
	cout << result << endl;

	cout << "*******test area*******" << endl;
	HugeInt a(34567);
	HugeInt b(56789);
	HugeInt c(-34567);
	HugeInt d(-56789);
	cout << a << " + " << b << " = " << a+b << endl;
	cout << a << " - " << b << " = " << a-b << endl;
	cout << b << " - " << a << " = " << b-a << endl;

	cout << b << " + " << c << " = " << b+c << endl;
	cout << b << " - " << c << " = " << b-c << endl;
	cout << c << " + " << b << " = " << c+b << endl;
	cout << c << " - " << b << " = " << c-b << endl;

	cout << c << " + " << d << " = " << c+d << endl;
	return 0;
}
