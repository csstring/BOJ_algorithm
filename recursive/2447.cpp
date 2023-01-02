//별찍기 10
#include <iostream>
using namespace std;
bool board[2300][2300];
void func(int x, int y, int n)
{
  if (n == 1){
    board[x][y] = true;
    return;
  }
  int nx = n /3;
  for (int i =0; i < 3; ++i){
    for (int j = 0; j < 3; ++j){
      if (i == 1 && j == 1) continue;
      func(x+ nx*i, y+nx*j,nx);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  func(0,0,n);
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      if (board[i][j]) cout << '*';
      else cout << ' ';
    }
    cout << '\n';
  }
}