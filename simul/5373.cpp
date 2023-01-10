//큐빙
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
char color[] = {'w', 'r', 'g', 'o', 'b', 'y'};
const int U = 0;
const int F = 1;
const int L = 2;
const int B = 3;
const int R = 4;
const int D = 5;
char board[6][3][3];
int n,Count;
char plane,dir;
void plan_rot(int k)
{
  char tmp[9];
  int index = 0;
  for (int i =0; i <3; ++i){
    for (int j = 0; j < 3; ++j){
      tmp[index++] = board[k][i][j];
    }
  }
  index = 0;
    for (int j =2; j >=0; --j)
      for (int i = 0; i < 3; ++i)
        board[k][i][j] = tmp[index++];
}
void edge_rot(int k, char p)
{
  int temp;
  int clock = 1;
  if (p == '-') clock = 3;
  while (clock >0)
  {
    clock--;
    plan_rot(k);
  for (int i = 0; i < 3; ++i)
  {
    if (k == 0)
    {
      temp = board[F][0][i];
      board[F][0][i] = board[R][0][i];
      board[R][0][i] = board[B][0][i];
      board[B][0][i] = board[L][0][i];
      board[L][0][i] = temp;
    }
    if (k == 1)//F
    {
      temp = board[U][2][i];
      board[U][2][i] = board[L][2-i][2];
      board[L][2-i][2] = board[D][0][2-i];
      board[D][0][2-i] = board[R][i][0];
      board[R][i][0] = temp;
    }
    if (k == 2) //L
    {
      temp = board[U][i][0];
      board[U][i][0] = board[B][2-i][2];
      board[B][2-i][2] = board[D][i][0];
      board[D][i][0] = board[F][i][0];
      board[F][i][0] = temp;
    }
    if (k == 3) //B
    {
      temp = board[U][0][i];
      board[U][0][i] = board[R][i][2];
      board[R][i][2] = board[D][2][2-i];
      board[D][2][2-i] = board[L][2-i][0];
      board[L][2-i][0] = temp;
    }
    if (k == 4) //R
    {
      temp = board[U][2-i][2];
      board[U][2-i][2] = board[F][2-i][2];
      board[F][2-i][2] = board[D][2-i][2];
      board[D][2-i][2] = board[B][i][0];
      board[B][i][0] = temp;
    }
    if (k == 5)
    {
      temp = board[F][2][i];
      board[F][2][i] = board[L][2][i];
      board[L][2][i] = board[B][2][i];
      board[B][2][i] = board[R][2][i];
      board[R][2][i] = temp;
    }
  }
  }
}
void edge_rrot(int k)
{
  int temp;
  for (int i = 0; i < 3; ++i)
  {
    if (k == 0)
    {
      temp = board[F][0][i];
      board[F][0][i] = board[L][0][i];
      board[L][0][i] = board[B][0][i];
      board[B][0][i] = board[R][0][i];
      board[R][0][i] = temp;
    }
    if (k == 1)//F
    {
      temp = board[U][2][i];
      board[U][2][i] = board[R][i][0];
      board[R][i][0] = board[D][0][i];
      board[D][0][i] = board[L][2-i][2];
      board[L][2-i][2] = temp;
    }
    if (k == 2) //L
    {
      temp = board[U][i][0];
      board[U][i][0] = board[F][i][0];
      board[F][i][0] = board[D][i][0];
      board[D][i][0] = board[B][2-i][2];
      board[B][2-i][2] = temp;
    }
    if (k == 3) //B
    {
      temp = board[U][0][i];
      board[U][0][i] = board[L][2-i][0];
      board[L][2-i][0] = board[D][2][2-i];
      board[D][2][2-i] = board[R][i][2];
      board[R][i][2] = temp;
    }
    if (k == 4) //R
    {
      temp = board[U][2-i][2];
      board[U][2-i][2] = board[B][i][0];
      board[B][i][0] = board[D][2-i][2];
      board[D][2-i][2] = board[F][2-i][2];
      board[F][2-i][2] = temp;
    }
    if (k == 5)
    {
      temp = board[F][2][i];
      board[F][2][i] = board[R][2][i];
      board[R][2][i] = board[B][2][i];
      board[B][2][i] = board[L][2][i];
      board[L][2][i] = temp;
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int tmp =0; tmp< n; ++tmp)
  {
    for (int i = 0; i< 6; ++i)
      for (int j = 0; j < 3; ++j)
        for (int k = 0; k <3; ++k)
          board[i][j][k] = color[i];
    cin >> Count;
    for (int i = 0; i < Count; ++i)
    {
      cin >> plane >> dir;
      int Case;
      if (plane == 'U') Case = U;
      if (plane == 'F') Case = F;
      if (plane == 'L') Case = L; 
      if (plane == 'B') Case = B; 
      if (plane == 'R') Case = R; 
      if (plane == 'D') Case = D;
      edge_rot(Case, dir);
    }
    for (int i =0; i <3; ++i){
      for (int j = 0; j <3; ++j){
        cout << board[0][i][j];
      }
      cout << '\n';
    }
  }
}