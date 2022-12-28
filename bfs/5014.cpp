#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int start, fin, total, up, down;
int Count[1000005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> total >> start >> fin >> up >> down;
  fill(Count, Count + 1000005, -1);
  queue<int> q;
  Count[start] = 0;
  q.push(start);
  while (Count[fin] == -1 && !q.empty())
  {
    int cur = q.front();
    q.pop();
    for (int nx : {cur + up, cur - down})
    {
      if (nx < 1 || nx > total) continue;
      if (Count[nx] != -1) continue;
      Count[nx] = Count[cur] + 1;
      q.push(nx);
    }
  }
  if (Count[fin] != -1)
    cout << Count[fin];
  else 
    cout << "use the stairs";
}