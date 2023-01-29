#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
int t,k,val;
char c;
multiset<int> ms;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--)
  {
    cin >> k;
    for (int i=0; i <k; ++i)
    {
      cin >> c >> val;
      if (c == 'I') ms.insert(val);
      else
      {
        if (ms.empty()) continue;
        if (val == -1) ms.erase(ms.begin());
        else ms.erase(--ms.end());
      }
    }
    if (ms.empty()) cout << "EMPTY\n";
    else cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
    ms.clear();
  }
}