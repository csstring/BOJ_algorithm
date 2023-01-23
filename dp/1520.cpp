#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;
int board[500][500];
int arr[500][500];
int func(int x, int y)
{
  if (arr[x][y] != -1) return arr[x][y];
  if (x == n-1 && y == m-1) return 1;
  int &ret = arr[x][y];
  ret = 0;
  for (int dir =0; dir < 4; ++dir)
  {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx <0 || ny <0 || nx >=n || ny >=m) continue;
    if (board[x][y] <= board[nx][ny]) continue;
    ret += func(nx,ny);
  }
  return ret;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >>n >>m;
  for (int i =0; i <n; ++i){
    for (int j =0; j<m; ++j){
      cin >> board[i][j];
      arr[i][j] = -1;
    }
  }
  cout << func(0,0);
}