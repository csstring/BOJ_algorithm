#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t arr[100001];
int board[100001];
int n,m,s,e;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>m;
  for (int i = 1; i <= n; ++i)
    cin >> board[i];
  arr[1] = board[1];
  for (int i = 2; i <=n; ++i)
  {
    arr[i] = arr[i-1] + board[i];
  }
  while (m--)
  {
    cin >> s >>e;
    cout << arr[e] - arr[s-1]<< '\n';
  }
}