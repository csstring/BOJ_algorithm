#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int ans,n,val;
int board[100001];
int arr[100001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <=n; ++i)
  {
    cin >> board[i];
  }
  ans = INT32_MIN;
  for (int i =1; i <=n; ++i)
  {
    arr[i] = board[i];
    if (arr[i-1] > 0) arr[i] += arr[i-1];
    ans = max(arr[i], ans);
  }
  cout << ans;
}