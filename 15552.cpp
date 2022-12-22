#include <iostream>

using namespace std;
int c, a,b;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> c;
  for (int i = 0; i < c; ++i)
  {
    cin >> a >> b;
    cout << a+b << '\n';
  }
}