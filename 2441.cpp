#include <iostream>

using namespace std;
int c;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> c;
  for (int i = 0; i < c; ++i)
  {
    for (int k = 0; k < i; ++k)
      cout << " ";
    for (int j = i; j < c; ++j)
      cout << "*";
    cout << '\n';
  }
}