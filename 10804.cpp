#include <iostream>
#include <algorithm>
using namespace std;
int a,b,Array[20];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 20; ++i)
    Array[i] = i + 1;
  for (int i = 0; i < 10; ++i)
  {
    cin >> a >> b;
    reverse(Array + a - 1, Array + b);
  }
  for (int i = 0; i < 20; ++i)
    cout << Array[i] << ' ';
}