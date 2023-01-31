#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
const int tmp = 1000000;
int board[1000][3];
int arr[3][1000][3];
int n,ans;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i)
    for (int j=0; j <3; ++j)
      cin >> board[i][j];
  arr[0][0][0] = board[0][0];arr[0][0][1] = tmp; arr[0][0][2] = tmp;
  arr[1][0][0] = tmp; arr[1][0][1] = board[0][1]; arr[1][0][2] = tmp;
  arr[2][0][1] = tmp; arr[2][0][2] = board[0][2]; arr[2][0][0] = tmp;
  ans = INT32_MAX;
  for (int k =0; k <3; ++k)
  {
    for (int i =1; i<n; ++i)
    {
      arr[k][i][0] = min(arr[k][i-1][1], arr[k][i-1][2]) + board[i][0];
      arr[k][i][1] = min(arr[k][i-1][0], arr[k][i-1][2]) + board[i][1];
      arr[k][i][2] = min(arr[k][i-1][0], arr[k][i-1][1]) + board[i][2];
    }
    for (int j =0; j <3; ++j){
      if (k == j) continue;
      ans = min(ans, arr[k][n-1][j]);
    }
  }
  cout << ans;
}