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
vector<int> pv[6] ={{1,2,3,4},{0,4,5,2},{0,1,5,3},{0,2,5,4},{0,3,5,1},{1,4,3,2}};
//{0 w} {1 r} {2 g} {3 o} {4 b} {5 y}
/*vector<int> U ={1,2,3,4};
vector<int> D ={1,4,3,2};
vector<int> F ={0,4,5,2};
vector<int> B ={0,2,5,4};
vector<int> L ={0,1,5,3};
vector<int> R ={0,3,5,1};
00 01 02
00 10 20
20 21 22
*/
char board[6][3][3];
int n,Count;
char plane,dir;
void plan_rot(int k, char p)
{
  char tmp[9];
  int index = 0;
  for (int i =0; i <3; ++i){
    for (int j = 0; j < 3; ++j){
      tmp[index++] = board[k][i][j];
    }
  }
  index = 0;
  if (p == '+'){
    for (int j =2; j >=0; --j)
      for (int i = 0; i < 3; ++i)
        board[k][i][j] = tmp[index++];
  }
  else{
    for (int j =0; j <3; ++j)
      for (int i = 2; i >= 0; --i)
        board[k][i][j] = tmp[index++];
  }
}
void edge_rot(int k, char p)
{
  char tmp[4][3];
  int clock = 1;
  if (p == '-') clock = 3;
  if (k == 0)
  {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        tmp[i][j] = board[pv[k][i]][0][j];
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        board[pv[k][(i +clock)%4]][0][j] = tmp[i][j];
  }
  if (k == 1)
  {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        tmp[i][j] = board[pv[k][i]][2][j];
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        board[pv[k][(i +clock)%4]][2][j] = tmp[i][j];
  }
  if (k == 2)
  {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        tmp[i][j] = board[pv[k][i]][j][0];
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        board[pv[k][(i +clock)%4]][j][0] = tmp[i][j];
  }
  if (k == 3)
  {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        tmp[i][j] = board[pv[k][i]][0][j];
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        board[pv[k][(i +clock)%4]][0][j] = tmp[i][j];
  }
  if (k == 4)
  {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        tmp[i][j] = board[pv[k][i]][j][2];
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        board[pv[k][(i +clock)%4]][j][2] = tmp[i][j];
  }
  if (k == 5)
  {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        tmp[i][j] = board[pv[k][i]][2][j];
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        board[pv[k][(i +clock)%4]][2][j] = tmp[i][j];
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
      if (plane == 'U') Case =0;
      if (plane == 'F') Case =1;
      if (plane == 'L') Case =2; 
      if (plane == 'B') Case =3; 
      if (plane == 'R') Case =4; 
      if (plane == 'D') Case =5;
      plan_rot(Case, dir);
      edge_rot(Case,dir); 
    }
    for (int i =0; i <3; ++i){
      for (int j = 0; j <3; ++j){
        cout << board[0][i][j];
      }
      cout << '\n';
    }
  }
}