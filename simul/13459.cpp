#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
//구슬탈출
using namespace std;
#define X first
#define Y second
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
char board[10][10];
int n,m,ans;
pair<int,int> Exit;
void ft_roll2(pair<int,int>& curR, char val, int dir)
{
  while (board[Exit.X][Exit.Y] == 'O')
  {
    int nx = curR.X + dx[dir];
    int ny = curR.Y + dy[dir];
    if (board[nx][ny] != '.' && board[nx][ny] != 'O') return;
    board[nx][ny] = val;
    board[curR.X][curR.Y] = '.';
    curR = {nx,ny};
  }
  if (board[Exit.X][Exit.Y] != 'O') board[Exit.X][Exit.Y] = 'O';
}
void ft_roll(pair<int,int>& NR, pair<int,int>& NB,int dir)
{
  bool flag;
  if (dir == 0) NR.X < NB.X ? flag = false : flag= true; //flase R먼저
  if (dir == 1) NR.Y < NB.Y ? flag = false : flag= true;
  if (dir == 2) NR.X > NB.X ? flag = false : flag= true;
  if (dir == 3) NR.Y > NB.Y ? flag = false : flag= true;
  if (flag == false)
  {
    ft_roll2(NR, 'R', dir);
    ft_roll2(NB, 'B', dir);
  }
  else
  {
    ft_roll2(NB, 'B', dir);
    ft_roll2(NR, 'R', dir);
  }
}
void run(pair<int,int> R, pair<int,int> B, int k)
{
  if (k == 11 || (R.X == Exit.X && R.Y == Exit.Y) || (B.X == Exit.X && B.Y == Exit.Y))
  {
    if (B.X != Exit.X || B.Y != Exit.Y) ans = min(ans, k);
    return;
  }
  for (int dir =0; dir <4; ++dir)
  {
    if (ans != 11) return;
    pair<int,int> NR = R;
    pair<int,int> NB = B;
    ft_roll(NR,NB,dir);
    char Rval = '.'; char Bval = '.';
    if (Exit.X == NR.X && Exit.Y == NR.Y) Rval = 'O';
    if (Exit.X == NB.X && Exit.Y == NB.Y) Bval = 'O';
    run(NR,NB,k+1);
    board[NR.X][NR.Y] = Rval; board[NB.X][NB.Y] = Bval;
    board[R.X][R.Y] = 'R'; board[B.X][B.Y] = 'B';
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  pair<int,int> R;
  pair<int,int> B;
  cin >> n>>m;
  ans = 11;
  for (int i = 0; i <n; ++i){
    for (int j = 0; j<m; ++j){
      cin >> board[i][j];
      if (board[i][j] == '#' || board[i][j] == '.') continue;
      if (board[i][j] == 'R') R = {i,j};
      if (board[i][j] == 'B') B = {i,j};
      if (board[i][j] == 'O') Exit = {i,j};
    }
  }
  run(R,B,0);
  if (ans == 11) ans = 0;
  else ans = 1;
  cout << ans;
}