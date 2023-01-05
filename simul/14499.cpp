#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define X 0
#define Y 1
int dice[2][4];
int board[20][20];
int dx[4] = {0, 0,-1,1};
int dy[4] = {1,-1,0,0};
int n,m,k,x,y,dir;
void dicerot(int axis, int clock)
{
  if (clock == 1)
    rotate(dice[axis], dice[axis] + 1, dice[axis] + 4);
  if (clock == -1)
    rotate(dice[axis], dice[axis] + 3, dice[axis] + 4);
  dice[(axis+1) %2][0]=dice[axis][0];
  dice[(axis+1) %2][2]=dice[axis][2];
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>m >>x>>y >>k;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j <m; ++j){
      cin >> board[i][j];
    }
  }
  for (int tmp = 0; tmp < k; ++tmp)
  {
    cin >> dir;
    int nx = x + dx[dir-1];
    int ny = y + dy[dir-1];
    if (nx < 0 || ny < 0 || nx >= n || ny >=m) continue;
    if (dx[dir-1] == 0) dicerot(Y,dy[dir-1]);
    if (dy[dir-1] == 0) dicerot(X,dx[dir-1]);
    if (board[nx][ny] == 0) board[nx][ny] = dice[X][2];
    else {
      dice[X][2] = board[nx][ny];
      dice[Y][2] = board[nx][ny];
      board[nx][ny] = 0;
    }
    x = nx; y = ny;
    cout << dice[X][0] << '\n';
  }
}