#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int board[100][100];
int Count[100][100];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string str;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i){ 
    cin >> str;
    for (int j = 0; j < m; ++j){
      board[i][j] = str[j] - 48; 
    }
  }
  Count[0][0] = 1;
  queue<pair<int, int>> q;
  q.push({0 ,0});
  while (!q.empty())
  {
    pair<int, int> cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx == n || ny == m) continue;
      if (board[nx][ny] == 0 || Count[nx][ny] != 0) continue;
      Count[nx][ny] = Count[cur.X][cur.Y] + 1;
      q.push({nx, ny});
    }
  }
  cout << Count[n - 1][m - 1];
}