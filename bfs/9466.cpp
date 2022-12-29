#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
const int NOT_VIS = 0;
const int CYCLE = -1;
int arr[100005];
int state[100005];
int total, n;
void run(int x)
{
  int cur = x;
  while (1)
  {
    state[cur] = x;
    cur = arr[cur];
    if (state[cur] == x)
    {
      while (state[cur] != CYCLE)
      {
        state[cur] = CYCLE;
        cur = arr[cur];
      }
      return;
    }
    else if (state[cur] != NOT_VIS)
    {
      return ;
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> total;
  for (int l = 0; l < total; ++l)
  {
    cin >> n;
    fill(state + 1, state + n + 1, 0);
    for (int i = 1; i < n + 1; ++i)
      cin >> arr[i];
    for (int i = 1; i < n + 1; ++i)
    {
      if (state[i] == NOT_VIS)
        run(i);
    }
    int cnt = 0;
    for (int i = 1; i < n + 1; ++i)
    {
      if (state[i] != CYCLE)
        cnt++;
    }
    cout << cnt << '\n';
  }
}