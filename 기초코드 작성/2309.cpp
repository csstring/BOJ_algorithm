#include <iostream>
#include <algorithm>
using namespace std;
int a,total[9], fix[7],val;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int f = 0; f< 9; ++f)
    cin >> total[f];
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      val= 0;
      a = 0;
      if (j <= i)
        continue;
      for (int k = 0; k <9; ++k)
      {
        if (k == i || k == j)
          continue;
        fix[a++] = total[k];
      }
      for (int b = 0; b < 7;++b)
        val += fix[b];
      if (val == 100)
        break;
    }
    if (val == 100)
        break;
  }
  sort(fix, fix +7);
  for (int b = 0; b < 7;++b)
        cout << fix[b] << '\n';
}