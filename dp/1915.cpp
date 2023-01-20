#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,m,ans,l;
char board[1000][1000];
int getsize(int i, int j)
{
  int tmp = 1;
  while (i + tmp != n && j + tmp != m)
  {
    int nx = i + tmp;
    int ny = j + tmp;
    for (int x = nx; x >= i; --x)
    {
      if (board[x][ny] == '0') return tmp;
    }
    for (int y = ny; y >= j; --y)
    {
      if (board[nx][y] == '0') return tmp;
    }
    tmp++;
  }
  return tmp;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>m;
  for (int i=0; i <n; ++i)
    for (int j =0; j <m; ++j)
      cin >> board[i][j];
  for (int i =0; i +ans < n; ++i){
    for (int j =0; j + ans <m; ++j)
    {
      if (board[i][j] =='0') continue;
      ans = max(ans,getsize(i,j));
    }
  }
  cout << ans * ans;
}