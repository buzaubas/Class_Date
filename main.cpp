#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Date cur(4, 5, 2017);
	Date bh(1, 2, 1999);

	cout << "С вашего дня рождения прошло " << (cur - bh) << " дней\n";

	cur = cur + 5;
	cur += 5;

	cur.show();	// 14.05.2017

	cin.get(); cin.get();
}
