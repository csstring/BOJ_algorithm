#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
#define R 0
#define G 1
#define B 2
int board[1000][3];
int arr[1000][3];
int n,ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i <n; ++i){
    for (int j = 0; j <3; ++j){
      cin >> board[i][j];
    }
  }
  arr[0][0] = board[0][0];
  arr[0][1] = board[0][1];
  arr[0][2] = board[0][2];
  for (int i = 1; i<n; ++i)
  {
    arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + board[i][0];
    arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + board[i][1];
    arr[i][2] = min(arr[i-1][0], arr[i-1][1]) + board[i][2];
  }
  ans = min(arr[n-1][0], arr[n-1][1]);
  ans = min(ans, arr[n-1][2]);
  cout << ans;
}