#include <iostream>

using namespace std;
int max_i, max_val, temp;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 9; ++i)
  {
    cin >> temp;
    if (temp > max_val)
    {
      max_i = i + 1;
      max_val = temp;
    }
  }
  cout << max_val << '\n';
  cout << max_i;
}