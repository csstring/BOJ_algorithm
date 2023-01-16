#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[1000];
int arr[1000];
int n,val;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i<n; ++i)
    cin >> board[i];
  arr[0] = board[0];
  for (int i =1; i<n; ++i)
  {
    arr[i] = board[i];
    for (int j = i-1; j >=0; --j)
    {
      if (board[j] >= board[i]) continue;
      arr[i] = max(arr[i], board[i] + arr[j]);
    }
  }
  cout << *max_element(arr, arr+n);
}