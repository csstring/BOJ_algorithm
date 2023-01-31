#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool xvis[9][10];
bool yvis[9][10];
bool svis[3][3][10];
int board[9][9];
char val;
void solve(int k)
{
  if (k==81)
  {
    for (int i =0; i <9; ++i){
      for (int j =0; j <9; ++j){
        cout << board[i][j];
      }
      cout << '\n';
    }
    exit(0);
  }
  int x = k / 9;
  int y = k % 9;
  if (board[x][y] != 0)
  {
    solve(k+1);
  }
  else
  {
    for (int i =1; i <=9; ++i)
    {
      if (xvis[x][i] || yvis[y][i] || svis[x/3][y/3][i]) continue;
      xvis[x][i] = true;
      yvis[y][i] = true;
      svis[x/3][y/3][i] = true;
      board[x][y] = i;
      solve(k+1);
      board[x][y] = 0;
      xvis[x][i] = false;
      yvis[y][i] = false;
      svis[x/3][y/3][i] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i =0; i<9; ++i)
    for (int j =0; j <9; ++j){
      cin >>val;
      board[i][j] = val -'0';
      if (board[i][j]){
        xvis[i][board[i][j]] = true;
        yvis[j][board[i][j]] = true;
        svis[i/3][j/3][board[i][j]] = true;
      }
    }
  solve(0);
}