#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, total;
bool vis[25][25];
int borad[25][25];
vector<int> ans;
string str;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i){
    cin >> str;
    for (int j = 0; j < n; ++j){
      borad[i][j] = str[j] - 48;
    }
  }
  for (int i = 0; i <n; ++i){
    for (int j = 0; j <n; ++j)
    {
      if (vis[i][j] == 1 || borad[i][j] == 0) continue;
      total++;
      queue<pair<int,int>> q;
      int size = 1;
      vis[i][j] = 1;
      q.push({i,j});
      while (!q.empty())
      {
        pair<int,int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || ny < 0|| nx >= n|| ny >= n) continue;
          if (vis[nx][ny] == 1 || borad[nx][ny] == 0) continue;
          size++;
          vis[nx][ny] = 1;
          q.push({nx,ny});
        }
      }
      ans.push_back(size);
    }
  }
  sort(ans.begin(), ans.end());
  cout << total;
  for (auto it = ans.begin(); it != ans.end(); ++it)
    cout << '\n' << *it;
}