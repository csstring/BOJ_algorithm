#include <iostream>

using namespace std;
size_t a,b;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  if (a > b)
  {
    cout << a - b - 1 << '\n';
    b++;
    for (;b != a; ++b)
      cout << b << ' ';
  }
  else if (a < b)
  {
    cout << b - a - 1 << '\n';
    a++;
    for (;a != b; ++a)
      cout << a << ' ';
  }
  else
    cout << 0 << '\n';
}