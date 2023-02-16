#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int n,val,t,total;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> total;
	while (total--)
	{
		cin >> n;
		cout << n << '\n';
		t = n/2;
		if (n % 6 == 2)
		{
			for (int i =1; i <t+1; ++i)
				cout << i*2-1 << ' ';
			cout << 2 << ' ';
			cout << 0 << ' ';
			for (int i =3; i <t; ++i)
				cout << i*2 << ' ';
			cout << 4 << ' ';
		}
		else if (n%6 ==3)
		{
			for (int i =2; i <t+1; ++i)
				cout << i*2-1 << ' ';
			cout << 1 << ' ';
			for (int i =2; i <t+1; ++i)
				cout << i*2 << ' ';
			cout << 0 << ' ';
			cout << 2 << ' ';
		}
		else {
			val = 2;
			cout << val-1 << ' ';
			for (int i =1; i <n; ++i)
			{
				val += 2;
				if (val > n) val = 1;
				cout << val-1 << ' ';
			}
		}
		cout << '\n';
	}
}