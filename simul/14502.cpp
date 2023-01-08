//연구소
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
#define X first
#define Y second
vector<pair<int,int>> blank;
int n,m,ans;
int board[8][8];
int dx[4] = {0, 0,-1,1};
int dy[4] = {1,-1,0,0};
int run(queue<pair<int,int>> q)
{
  int vis[8][8] = {};
  while (!q.empty())
  {
    pair<int,int> cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0|| ny < 0 || nx >=n || ny >=m ) continue;
      if (vis[nx][ny] == 1 || board[nx][ny] != 0) continue;
      vis[nx][ny] = 1;
      q.push({nx,ny});
    }
  }
  int tans = 0;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j <m; ++j){
      if (board[i][j] == 0 && vis[i][j] == 0) tans++;
    }
  }
  return tans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int,int>> q;
  
  cin >> n >> m;
  for (int i =0; i <n; ++i){
    for (int j = 0; j <m; ++j){
      cin >> board[i][j];
      if (board[i][j] == 2) q.push({i,j});
      if (board[i][j] == 0) blank.push_back({i,j});
    }
  }

  vector<int> c (blank.size()-3, 0);
  c.push_back(1);c.push_back(1);c.push_back(1);
  do {
    stack<pair<int,int>> st;
    for (int i =0; i <blank.size(); ++i)
    {
      if (c[i] == 0) continue;
      pair<int,int> cur = blank[i];
      st.push({cur.X, cur.Y});
      board[cur.X][cur.Y] = 1;
    }
    ans = max(ans, run(q));
    while (!st.empty()) {
      board[st.top().X][st.top().Y] = 0;
      st.pop();
    }
  }while (next_permutation(c.begin(), c.end()));
  cout << ans;
}