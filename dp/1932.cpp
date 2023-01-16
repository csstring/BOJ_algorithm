#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[504][504];
int arr[504][504];
int n,ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =1; i <=n; ++i){
    for (int j = 1; j <=i; ++j){
      cin >> board[i][j];
    }
  }
  arr[1][1] = board[1][1];
  for (int i = 2; i <=n; ++i)
  {
    for (int j = 0; j <= i; ++j)
    {
      arr[i][j] = max(arr[i-1][j-1],arr[i-1][j]) + board[i][j];
    }
  }
  cout << *max_element(arr[n]+1, arr[n]+1+n);
}