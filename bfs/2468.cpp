#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<int> ans;
set<int> rain;
int n;
int borad[100][100];
bool vis[100][100];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i =0; i <n; ++i){
    for (int j = 0; j < n; ++j){
      cin >> borad[i][j];
      rain.insert(borad[i][j]);
    }
  }
  for (auto h = rain.begin(); h != rain.end(); ++h)
  {
    for (int i = 0; i < n; ++i)
      fill(vis[i], vis[i] + n, 0);
    int total = 0;
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j)
      {
        if (vis[i][j] == 1 || borad[i][j] <= *h) continue;
        total++;
        queue<pair<int,int>> q;
        vis[i][j] = 1;
        q.push({i,j});
        while (!q.empty())
        {
          pair<int,int> cur = q.front();
          q.pop();
          for (int dir = 0; dir<4; ++dir)
          {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0|| ny < 0 || nx >= n || ny >= n) continue;
            if (vis[nx][ny] == 1 || borad[nx][ny] <= *h) continue;
            vis[nx][ny] = 1;
            q.push({nx,ny});
          }
        }
      }
    }
    ans.push_back(total);
  }
  cout << max(*max_element(ans.begin(), ans.end()), 1);
}