//별찍기 11
#include <iostream>
using namespace std;
const int MAX = 1024 * 3 + 2;
bool board[MAX][MAX * 2 - 1];

void printStar(int x, int y)
{
  board[x][y] = true;
  board[x + 1][y-1] = true; board[x + 1][y+1] = true;
  for (int i = -2; i<= 2; ++i)
    board[x + 2][y + i] = true;
}
void func(int x, int y, int n)
{
  if (n == 3) {
    printStar(x,y);
    return;
  }
  int nx = n /2;
  func(x,y,nx);
  func(x+nx, y-nx, nx);
  func(x+nx, y+nx, nx);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  func(0,n - 1,n);
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < 2*n - 1; ++j){
      if (board[i][j]) cout << '*';
      else cout << ' ';
    }
    cout << '\n';
  }
}