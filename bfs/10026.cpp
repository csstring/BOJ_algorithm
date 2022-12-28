#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
char borad1[100][100];
char borad2[100][100];
bool vis1[100][100];
bool vis2[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, v1, v2;
string str;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i){
    cin >> str;
    for (int j = 0; j < n; ++j){
      borad1[i][j] = str[j];
      if (str[j] == 'R')
        borad2[i][j] = 'G';
      else
        borad2[i][j] = str[j];
    }
  }
  queue<pair<int,int>> q1;
  queue<pair<int,int>> q2;

  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j)
    {
      if (vis1[i][j] == 1) continue;
      v1++;
      q1.push({i, j});
      vis1[i][j] = 1;
      while (!q1.empty())
      {
        pair<int,int> cur = q1.front();
        q1.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || ny < 0 || nx == n|| ny == n) continue;
          if (vis1[nx][ny] == 1 || borad1[nx][ny] != borad1[cur.X][cur.Y]) continue;
          vis1[nx][ny] = 1;
          q1.push({nx,ny});
        }
      }
    }
  }
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j)
    {
      if (vis2[i][j] == 1) continue;
      v2++;
      q2.push({i, j});
      vis2[i][j] = 1;
      while (!q2.empty())
      {
        pair<int,int> cur = q2.front();
        q2.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || ny < 0 || nx == n|| ny == n) continue;
          if (vis2[nx][ny] == 1 || borad2[nx][ny] != borad2[cur.X][cur.Y]) continue; 
          vis2[nx][ny] = 1;
          q2.push({nx,ny});
        }
      }
    }
  }
  cout << v1 << ' ' << v2;
}