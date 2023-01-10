#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[105][105];
int r,c,k,mr,mc;
int Carr[105];
int Iarr[105];
int Qarr[105];
queue<int> q[105];
void runRow()
{
  for (int l = 0; l < mr; ++l)
  {
    int index = 0;
    int qdex = 0;
    int val;
    for (int i = 0; i < mc; ++i){
      if (board[l][i] == 0) continue;
      val = board[l][i];
      if (Carr[val] == 0) Iarr[index++] = val;
      Carr[val]++;
    }
    if (index == 0) continue;
    sort(Iarr, Iarr + index);
    for (int i =0; i < index; ++i){
      q[Carr[Iarr[i]]].push(Iarr[i]);
      Qarr[qdex++] = Carr[Iarr[i]];
      Carr[Iarr[i]] = 0; Iarr[i] = 0;
    }
    sort(Qarr, Qarr + qdex);
    int tmp= 0;
    for (int i = 0; i < qdex; ++i)
    {
      if (tmp < 100){
        board[l][tmp++] = q[Qarr[i]].front();
        board[l][tmp++] = Qarr[i];
      } 
      q[Qarr[i]].pop();
      Qarr[i] = 0;
    }
    if (tmp < mc)
      fill(board[l]+tmp, board[l] + mc,0);
    mc = max(tmp, mc);
  } 
}
void runCol()
{
  for (int l = 0; l < mc; ++l)
  {
    int index = 0;
    int qdex = 0;
    int val;
    for (int i = 0; i < mr; ++i){
      if (board[i][l] == 0) continue;
      val = board[i][l];
      if (Carr[val] == 0) Iarr[index++] = val;
      Carr[val]++;
    }
    if (index == 0) continue;
    sort(Iarr, Iarr + index);
    for (int i =0; i < index; ++i){
      q[Carr[Iarr[i]]].push(Iarr[i]);
      Qarr[qdex++] = Carr[Iarr[i]];
      Carr[Iarr[i]] = 0; Iarr[i] = 0;
    }
    sort(Qarr, Qarr + qdex);
    int tmp= 0;
    for (int i = 0; i < qdex; ++i)
    {
      if (tmp < 100){
        board[tmp++][l] = q[Qarr[i]].front();
        board[tmp++][l] = Qarr[i];
      } 
      q[Qarr[i]].pop();
      Qarr[i] = 0;
    }
    if (tmp < mr){
      for (int i = tmp; i < mr; ++i)
        board[i][l] = 0;
    }
    mr = max(tmp, mr);
  } 
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c>> k;
  for (int i =0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> board[i][j];
  int time = 0;
  mr = 3; mc = 3;
  while (board[r-1][c-1] != k && time <= 100)
  {
    if (mr >= mc) runRow();
    else runCol();
    time++;
  }
  if (time > 100) cout << -1;
  else cout << time;
}