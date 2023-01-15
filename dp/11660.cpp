#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[1025][1025];
int ans,x1,x2,y1,y2,n,m,val;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>m;
  for (int i =1; i<= n; ++i){
    for (int j =1; j <= n; ++j){
      cin >> val;
      board[i][j] = board[i][j-1] + val;
    }
  }
  while (m--)
  {
    cin >> x1 >>y1 >>x2 >>y2;
    ans = 0;
    for (int i = x1; i <=x2; ++i)
    {
      ans += board[i][y2] - board[i][y1-1];
    }
    cout << ans << '\n';
  }
}