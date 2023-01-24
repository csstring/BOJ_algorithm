#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[1000001];
int n,ac,mx;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i<n; ++i)
  {
    cin >> ac;
    board[ac] = board[ac-1] + 1;
    mx = max(mx, board[ac]);
  }
  cout << n - mx;
}