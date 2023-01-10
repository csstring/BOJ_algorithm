#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[100][100];
int r,c,k,mr,mc;
int arr[100];
void runRow()
{
  for (int l = 0; l < mr; ++l)
  {
    stack<int> st;
    
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
  }
  if (time > 100) cout << -1;
  else cout << time;
}