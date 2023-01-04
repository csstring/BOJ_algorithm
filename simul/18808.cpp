//스티커 붙이기
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m,k,r,c;
int stick[12][12];
int board[42][42];
void ft_rotate()
{
  int tmp[12][12];
  for (int i  = 0; i <r; ++i){
    for (int j = 0; j <c; ++j){
      tmp[i][j] = stick[i][j];
    }
  }
  for (int i =0; i <c; ++i){//5
    for (int j = 0; j <r; ++j){//2
      stick[i][j] = tmp[r-1-j][i];
    }
  }
  swap(r,c);
}

bool ft_check(int x, int y)
{
  for (int i = 0; i < r; ++i){
    for (int j = 0; j <c; ++j){
      if (stick[i][j] == 1 && board[x+i][y+j] == 1) return false;
    }
  }
  for (int i = 0; i < r; ++i){
    for (int j = 0; j <c; ++j){
      if (stick[i][j] == 1) board[x+i][y+j] = 1;
    }
  }
  return true;
}
void ft_post()
{
  for (int rot = 0; rot <4; ++rot)
    {
      for (int x = 0; x <= n - r; ++x)
      {
        for (int y = 0; y <= m - c; ++y)
        {
          if (ft_check(x,y)) return;
        }
      }
      ft_rotate();
    }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n>>m >> k;
  for (int l = 0; l < k; ++l)
  {
    cin >> r >>c;
    for (int i = 0; i < r; ++i){
      for (int j = 0; j <c; ++j){
        cin >> stick[i][j];
      }
    }
    ft_post();
  }
  int ans = 0;
  for (int i = 0; i <n; ++i){
    for (int j = 0; j<m; ++j){
      ans += board[i][j];
    }
  }
  cout << ans;
}