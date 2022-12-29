#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int n, k;
int Count[100005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  fill(Count, Count + 100005, -1);
  queue<int> q;
  q.push(n);
  Count[n] = 0;
  while (Count[k] == -1 && !q.empty())
  {
    int cur = q.front();
    q.pop();
    int multi = cur;
    while (1)
    {
      multi *= 2;
      if (multi < 0 || multi > 100000) break;
      if (Count[multi] != -1) break;
      Count[multi] = Count[cur];
      q.push(multi);
    }
    for (int nx : {cur - 1, cur + 1})
    {
      if (nx < 0 || nx > 100000) continue;
      if (Count[nx] != -1) continue;
      Count[nx] = Count[cur] + 1;
      q.push(nx);
    }
  }
  cout << Count[k];
}