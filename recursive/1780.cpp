//종이의 개수
#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int m,z,p;
int board[2200][2200];
bool check(int x, int y, int n)
{
  int val = board[x][y];
  for (int i = x; i < x + n; ++i){
    for (int j = y; j < y + n; ++j){
      if (board[i][j] != val) return (false);
    }
  }
  if (val == -1) m += 1;
  if (val == 0) z += 1;
  if (val == 1) p += 1;
  return (true);
}

void func(int x,int y, int n)
{
  if (check(x,y,n))
    return;
  int nextn = n / 3;
  for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 3; ++j){
      func(x + i*nextn, y+ j*nextn, nextn);
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      cin >> board[i][j];
    }
  }
  func(0,0,n);
  cout << m << '\n' << z << '\n' << p;
}