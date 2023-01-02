//쿼드트리
#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
char board[70][70];

bool  check(int x, int y, int n)
{
  char val = board[x][y];
  for (int i =x; i<x+n; ++i){
    for (int j =y; j <y+n; ++j){
      if (board[i][j] != val) return false;
    }
  }
  cout << val;
  return true;
}

void func(int x, int y, int n)
{
  if (check(x,y,n)){
    return;
  }
  int nx = n / 2;
  for (int i = 0; i < 2; ++i){
    for (int j = 0; j < 2; ++j){
      if (i == 0 && j == 0) cout << '(';
      func(x + i*nx, y+ j*nx, nx);
    }
  }
  cout << ')';
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n ;++i){
    for (int j = 0; j < n; ++j){
      cin >> board[i][j];
    }
  }
  func(0,0,n);
}