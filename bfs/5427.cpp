#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int total, n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int borad[1000][1000];
int Exit[1000][1000];
int fire[1000][1000];
string str;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> total;
  for (int l = 0; l < total; ++l)
  {
    int flag = 0;
    cin >> m >> n;
    queue<pair<int,int>> fq;
    queue<pair<int,int>> eq;
    for (int i = 0; i < n; ++i)
    {
      cin >> str;
      fill(Exit[i], Exit[i] + m, -1);
      fill(fire[i], fire[i] + m, -1);
      for (int j = 0; j < m; ++j){
        borad[i][j] = str[j];
        if (borad[i][j] == '@'){
          eq.push({i,j});
          Exit[i][j] = 0;
        }
        if (borad[i][j] == '*'){
          fq.push({i, j});
          fire[i][j] = 0;
        }
      }
    }
    while (!fq.empty())
    {
      pair<int,int> cur = fq.front();
      fq.pop();
      for (int dir = 0; dir < 4; ++dir){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || ny < 0 || nx == n || ny == m) continue;
        if (fire[nx][ny] != -1 || borad[nx][ny] == '#') continue;
        fire[nx][ny] = fire[cur.X][cur.Y] + 1;
        fq.push({nx, ny});
      }
    }
    while (!eq.empty())
    {
      pair<int,int> cur = eq.front();
      eq.pop();
      for (int dir = 0; dir < 4; ++dir){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || ny < 0 || nx == n || ny == m){
          cout << Exit[cur.X][cur.Y] + 1 << '\n';
          flag = 1;
          break;
        }
        if (Exit[nx][ny] != -1 || borad[nx][ny] == '#') continue;
        if (fire[nx][ny] != -1 && fire[nx][ny] <= Exit[cur.X][cur.Y] + 1) continue;
        Exit[nx][ny] = Exit[cur.X][cur.Y] + 1;
        eq.push({nx, ny});
      }
      if (flag)
        break;
    }
    if (!flag)
      cout << "IMPOSSIBLE\n";
  }
}