#include <iostream>

using namespace std;
int c,k;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> c;
  c++;
  for (int i = 1; i < c; ++i)
  {
    k = 0;
    while (k < i)
    {
      k++;
      cout << '*';
    }
    cout << '\n';
  }
}