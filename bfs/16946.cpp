//벽부수고 이동4
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <set>
using namespace std;
#define X first
#define Y second
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int board[1000][1000];
int ans[1000][1000];
int color[1000][1000];
int n,m, col;
char val;
void bfs(int i, int j)
{
  queue<pair<int,int>> q;
  stack<pair<int,int>> st;
  board[i][j] = 1;
  q.push({i,j});
  st.push({i,j});
  while(!q.empty())
  {
    pair<int,int> cur = q.front(); q.pop();
    for (int dir =0; dir <4; ++dir)
    {
      int nx = cur.X +dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny <0 || nx>= n || ny >= m) continue;
      if (board[nx][ny] != 0) continue;
      q.push({nx,ny});
      st.push({nx,ny});
      board[nx][ny] = board[cur.X][cur.Y] + 1;
    }
  }
  int mx = st.size();
  while (!st.empty())
  {
    pair<int,int> cur =st.top(); st.pop();
    board[cur.X][cur.Y] = mx;
    color[cur.X][cur.Y] = col;
  }
  col++;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  col = 1;
  cin >> n >>m;
  for (int i = 0 ; i <n; ++i){
    for (int j = 0; j < m ; ++j){
      cin >> val;
      if (val == '1') board[i][j] = -1;
    }
  }
  for (int i = 0; i<n; ++i){
    for (int j = 0; j < m; ++j){
      if (board[i][j] == 0) bfs(i,j);
    }
  }
  for (int i = 0; i<n; ++i){
    for (int j = 0; j < m; ++j)
    {
      if (board[i][j] != -1) continue;
      int total = 1;
      int arr[4] = {};
      for (int dir =0; dir <4; ++dir)
      {
        int nx = i +dx[dir];
        int ny = j +dy[dir];
        bool flag = true;
        if (nx < 0 || ny <0 || nx>= n || ny >= m) continue;
        if (board[nx][ny] == -1) continue;
        int tcol = color[nx][ny];
        for (int k =0; k <4; ++k)
        {
          if (arr[k] == tcol) flag = false;
        }
        if (flag){
          total += board[nx][ny];
          arr[dir] = tcol;
        }
      }
      ans[i][j] = total;
    }
  }
  for (int i = 0; i <n; ++i){
    for (int j = 0; j <m; ++j){
      cout << ans[i][j] % 10;
    }
    cout << '\n';
  }
}