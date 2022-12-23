#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string src, dst;
int sarr[26], darr[26], ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> src >> dst;
  for (int i = 0; i < 1000; ++i)
  {
    if (i < src.size())
      sarr[src[i] - 97]++;
    if (i < dst.size())
      darr[dst[i] - 97]++;
    if (i >= src.size() && i >= dst.size())
      break;
  }
  for (int j = 0; j < 26; ++j)
    ans += abs(sarr[j] - darr[j]);
  cout << ans;
}