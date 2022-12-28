#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int Count[300][300];
int n, total_test,x,y;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> total_test;
  for (int l = 0; l < total_test; ++l)
  {
    pair<int,int> start, finsh;
    cin >> n >> x >> y;
    start = {x, y};
    cin >> x >> y;
    finsh = {x ,y};
    for (int i = 0; i < n; ++i)
      fill(Count[i], Count[i] + n, -1);
    queue<pair<int,int>> q;
    Count[start.X][start.Y] = 0;
    q.push({start.X, start.Y});
    while (Count[finsh.X][finsh.Y] == -1)
    {
      pair<int,int> cur = q.front();
      q.pop();
      for (int dir = 0; dir < 8; ++dir)
      {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (Count[nx][ny] != -1) continue;
        Count[nx][ny] = Count[cur.X][cur.Y] + 1;
        q.push({nx,ny});
      }
    }
    cout << Count[finsh.X][finsh.Y] << '\n';
  }
}