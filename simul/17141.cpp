//연구소2
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
int n,m,ans,cnt;
int board[50][50];
int Carr[10];
int vis[50][50];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>> q;
vector<pair<int,int>> virus;
int run()
{
  pair<int,int> cur;
  int time = 0;
  int total = 0;
  while (!q.empty() && total != cnt)
  {
    cur = q.front(); q.pop();
    for (int dir = 0; dir <4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny <0 || nx >= n|| ny>= n) continue;
      if (vis[nx][ny] != -1 || board[nx][ny] == 1) continue;
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      q.push({nx,ny});
      total++;
    }
  }
  while (!q.empty()){
    cur = q.front(); q.pop();
  }
  if (total == cnt) return vis[cur.X][cur.Y];
  else return ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>m;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      cin >>board[i][j];
      if (board[i][j] == 2) virus.push_back({i,j});
      if (board[i][j] == 1) continue; 
      cnt++;
    }
  }
  cnt -= m;
  ans = INT32_MAX;
  int vsize = virus.size();
  fill(Carr + m,Carr+ vsize,1);
  do {
    for (int i = 0; i < n; ++i)
      fill(vis[i], vis[i] + n, -1);
    for (int i =0; i < vsize; ++i)
    {
      if (Carr[i] == 1) continue;
      pair<int,int> cur = virus[i];
      q.push(cur);
      vis[cur.X][cur.Y] =0;
    }
    ans = min(ans,run());
  }while (next_permutation(Carr, Carr+vsize));
  if (ans == INT32_MAX) ans = -1;
  cout << ans;
}