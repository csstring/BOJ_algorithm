//색종이 만들기
#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int w,b;
int board[130][130];
int n;

bool check(int x, int y, int n)
{
  int val = board[x][y];
  for (int i = x; i < x + n; ++i){
    for (int j = y; j < y +n; ++j){
      if (board[i][j] != val) return false;
    }
  }
  if (val == 1) b++;
  if (val == 0) w++;
  return true;
}

void func(int x, int y, int n)
{
  if (check(x,y,n))
    return;
  int nx = n / 2;
  for (int i = 0; i < 2; ++i){
    for (int j = 0; j < 2; ++j){
      func(x + i *nx, y+ j*nx, nx);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      cin >> board[i][j];
    }
  }
  func(0,0,n);
  cout << w << '\n' << b;
}
