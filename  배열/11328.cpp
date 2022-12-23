#include <iostream>
#include <string>
using namespace std;
int sarr[26], darr[26], Count;
string src, dst;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> Count;
  for (int i = 0; i < Count; ++i)
  {
    cin >> src >> dst;
    for (int j = 0; j < 1000; ++j)
    {
      if (j == src.size() || j == dst.size())
        break;
      sarr[src[j] - 97]++;
      darr[dst[j] - 97]++;
    }
    for (int k = 0; k < 26; ++k)
    {
      if (sarr[k] != darr[k])
      {
        cout << "Impossible\n";
        break;
      }
      else if (k == 25 && (sarr[k] == darr[k]))
        cout << "Possible\n";
    }
    fill(sarr, sarr + 26, 0);
    fill(darr, darr + 26, 0);
  }
}