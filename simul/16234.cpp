//인구이동
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
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int,int>> v;
int board[50][50];
int N,R,L,ans;
bool run()
{
  bool vis[50][50] = {};
  bool flag = false;
  for (int i =0; i <N; ++i){
    for (int j = 0; j <N; ++j)
    {
      if (vis[i][j]) continue;
      queue<pair<int,int>> q;
      stack<pair<int,int>> st;
      vis[i][j] = 1;
      q.push({i,j}); st.push({i,j});
      int total = board[i][j];
      while (!q.empty())
      {
        pair<int,int> cur = q.front(); q.pop();
        for (int dir = 0; dir <4; ++dir)
        {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
          if (vis[nx][ny]) continue;
          int range = abs(board[nx][ny] - board[cur.X][cur.Y]);
          if (range < L || range > R) continue;
          vis[nx][ny] = 1;
          q.push({nx,ny});
          st.push({nx,ny});
          total += board[nx][ny];
        }
      }
      if (st.size() > 1) flag = true;
      total /= st.size();
      while (!st.empty()){
        pair<int,int> cur = st.top(); st.pop();
        board[cur.X][cur.Y] = total;
      }
    }
  }
  return flag;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> L >> R;
  for (int i = 0; i <N; ++i){
    for (int j = 0; j <N; ++j){
      cin >> board[i][j];
    }
  }
  while (run()) ans++;
  cout << ans;
}