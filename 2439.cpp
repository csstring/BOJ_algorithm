#include <iostream>

using namespace std;
int c,k;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> c;
  for (int i = 1; i <= c; ++i)
  {
    k = 1;
    while (k <= c)
    {
      if (c - i < k)
        cout << '*';
      else
        cout << ' ';
      k++;
    }
    cout << '\n';
  }
}