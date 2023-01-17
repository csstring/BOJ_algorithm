#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[3][31][1001];
int board[1001];
int t,w,val,ans1,ans2;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t>>w;
  for (int i=1; i <= t; ++i){
    cin >> val;
    board[i] = val;
  }
  for (int i =1; i <=t; ++i)
  {
    for (int j =0; j <=w ; ++j)
    {
      arr[1][j][i] = arr[1][j][i-1];
      arr[2][j][i] = arr[2][j][i-1];
      if (j != 0)
      {
        arr[1][j][i] = max(arr[1][j][i], arr[2][j-1][i-1]);
        arr[2][j][i] = max(arr[2][j][i], arr[1][j-1][i-1]);
      }
    }
    int place = board[i];
    for (int j = 0; j <= w; ++j)
    {
      if ((place == 1 && j % 2 == 0) || (place == 2 && j%2 == 1))
        arr[place][j][i]++;
    }
  }
  for (int i =0; i <=w; ++i)
  {
    ans1 = max(ans1, arr[1][i][t]);
    ans2 = max(ans2, arr[2][i][t]);
  }
  cout << max(ans1, ans2);
}