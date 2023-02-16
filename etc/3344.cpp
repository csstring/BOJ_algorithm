#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int n,val,t;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	t = n/2;
	if (n % 6 == 2)
	{
		for (int i =1; i <t+1; ++i)
			cout << i*2 << '\n';
		cout << 3 << '\n';
		cout << 1 << '\n';
		for (int i =3; i <t; ++i)
			cout << i*2 +1 << '\n';
		cout << 5 << '\n';
	}
	else if (n%6 ==3)
	{
		for (int i =2; i <t+1; ++i)
			cout << i*2 << '\n';
		cout << 2 << '\n';
		for (int i =2; i <t+1; ++i)
			cout << i*2 +1 << '\n';
		cout << 1 << '\n';
		cout << 3 << '\n';
	}
	else {
		val = 2;
		cout << val << '\n';
		for (int i =1; i <n; ++i)
		{
			val += 2;
			if (val > n) val = 1;
			cout << val << '\n';
		}
	}
}