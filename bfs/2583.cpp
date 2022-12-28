#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<int> ans;
int n,m,k,x1,x2,y1,y2,total;
int board[100][100];
bool vis[100][100];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i){
    cin >> y1 >> x1 >> y2 >> x2;
    for (int j = x1; j < x2; j++){
      for (int l = y1; l < y2; l++){
        board[j][l] = 1;
      }
    }
  }
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j)
    {
      if (vis[i][j] == 1 || board[i][j] == 1) continue;
      total++;
      queue<pair<int,int>> q;
      vis[i][j] = 1;
      q.push({i,j});
      int size = 1;
      while (!q.empty())
      {
        pair<int,int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if (vis[nx][ny] == 1 || board[nx][ny] == 1) continue;
          vis[nx][ny] = 1;
          size++;
          q.push({nx,ny});
        }
      }
      ans.push_back(size);
    }
  }
  cout << total << '\n';
  sort(ans.begin(), ans.end());
  for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
    cout << *it << ' ';
}