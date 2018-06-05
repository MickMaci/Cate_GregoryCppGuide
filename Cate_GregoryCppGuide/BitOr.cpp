#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, k;
	cin >> x >> k;
	int numer_rozwiazania = 0;
	int i=1;
	int x_plus_i = x + i;
	int x_BitOr_i = x | i;
	for (i; i < 2000000000; i++)
	{
		if ((x_plus_i = x + i) == (x_BitOr_i = x|i))
		{
			numer_rozwiazania++;
			if (numer_rozwiazania == k) break;

		}

	}
	cout << i;
	return 0;
}