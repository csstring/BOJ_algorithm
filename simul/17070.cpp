//파이프 옮기기1
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#define X first
#define Y second
using namespace std;
#define R 1
#define D 0
#define C 3
vector<pair<size_t,size_t>> m[3];
size_t board[32][32];
size_t n,ans;
void pipeinit()
{
  m[0] = {{0,1}};
  m[1] = {{1,0}};
  m[2] ={{0,1},{1,0},{1,1}};
}
void run(size_t x,size_t y, size_t dir)
{
  if (x == n -1 && y == n-1)
  {
    ans++;
    return;
  }
  for (size_t i = 0; i < 3; ++i)
  {
    if (dir == i) continue;
    bool flag = true;
    for (pair<size_t,size_t> cur : m[i])
    {
      size_t nx = cur.X + x;
      size_t ny = cur.Y + y;
      if (nx < 0 || ny <0 ||nx >=n || ny >= n || board[nx][ny]){
        flag = false;
        break;
      }
    }
    if (flag == false) continue;
    if (i == 0) run(x,y+1,R);
    else if (i == 1) run(x+1, y, D);
    else run(x+1,y+1,C);
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  pipeinit();
  for (size_t i = 0; i < n ; ++i){
    for (size_t j = 0 ; j < n; ++j){
      cin >> board[i][j];
    }
  }
  run(0,1,R);
  cout << ans;
}