//드래곤 커브
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
bool vis[101][101];
int x,y,d,g,n,ans;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
vector<int> v;
void run(int k)
{
  if (k == g + 1) return;
  if (k ==0)
  {
    int nx = x +dx[d];
    int ny = y +dy[d];
    vis[nx][ny] = 1;
    v[0] = d;
    x = nx; y = ny;
  }
  else
  {
    int tsize = 1 << (k-1);
    for (int i =tsize-1; i >=0; --i)
    {
      int nd = (v[i] +1)%4;
      v[tsize] = nd; tsize++;
      int nx = x +dx[nd];
      int ny = y +dy[nd];
      vis[nx][ny] = 1;
      x = nx; y=ny;
    }
  }
  run(k+1);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  v.resize(1024);
  for (int i =0 ; i< n; ++i)
  {
    cin >>y >>x>>d>>g;
    vis[x][y] = 1;
    run(0);
  }
  for (int i = 0; i < 100; ++i){
    for (int j = 0; j < 100; ++j)
    {
      if (!vis[i][j] || !vis[i+1][j]||!vis[i][j+1]||!vis[i+1][j+1]) continue;
      ans++;
    }
  }
  cout << ans;
}