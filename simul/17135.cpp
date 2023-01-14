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
int dx[3] = {0,-1,0};
int dy[3] = {-1,0,1};
vector<pair<int,int>> bow;
int combie[15];
int board[15][15];
int board2[15][15];
int vis[15][15];
int n,m,dis,ans;
bool movecheck()
{
  for (int j = 0; j <m; ++j){
    for (int i =n-1; i>0; --i){
      board2[i][j] = board2[i-1][j];
    }
  }
  fill(board2[0],board2[0] +m,0);
  for (int i =0; i<n; ++i){
    for (int j = 0; j<m; ++j){
      if (board2[i][j]) return true;
    }
  }
  return false;
}
int run()
{
  int total = 0;
  while (1)
  {
    stack<pair<int,int>> st;
    for (int i =0; i < bow.size(); ++i)
    {
      for (int i = 0; i <n; ++i)
        fill(vis[i],vis[i] +m,0);
      pair<int,int> tmp = bow[i];
      queue<pair<int,int>> q;
      q.push({tmp.X-1, tmp.Y});
      vis[tmp.X-1][tmp.Y] =1;
      while (!q.empty())//bfs
      {
        pair<int,int> cur = q.front(); q.pop();
        if (vis[cur.X][cur.Y] > dis) break;
        if (board2[cur.X][cur.Y] == 1)
        {
          st.push({cur.X,cur.Y});
          break;
        }
        for (int dir =0; dir <3; dir++)
        {
          int nx= cur.X +dx[dir];
          int ny = cur.Y +dy[dir];
          if (nx < 0 || ny<0 || nx >= n|| ny>= m) continue;
          if (vis[nx][ny] != 0) continue;
          vis[nx][ny] = vis[cur.X][cur.Y] + 1;
          q.push({nx,ny});
        }
      }
    }
    while (!st.empty()){
      pair<int,int> cur = st.top(); st.pop();
      if (board2[cur.X][cur.Y]){
        board2[cur.X][cur.Y] = 0;
        total++;
      }
    }
    if (!movecheck()) return total; 
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>m>> dis;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j<m; ++j){
      cin >> board[i][j];
    }
  }
  fill(combie +m -3,combie +m,1);
  do {
    bow.clear();
    for (int i = 0; i < n; ++i)
      for (int j = 0; j< m; ++j)
        board2[i][j] = board[i][j];
    for (int i = 0; i <m; ++i)
    {
      if (combie[i] == 0) continue;
      bow.push_back({n,i});
    }
    ans = max(ans, run());
  }while(next_permutation(combie, combie+m));
  cout << ans;
}