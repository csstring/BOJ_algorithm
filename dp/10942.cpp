// 팰린드롬?
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,m,s,e;
int arr[2001][2001];
int board[2001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =1; i <=n; ++i){
    cin >> board[i];
    arr[i][i] = 1;
  }
  for (int w = 1; w <= n -1; ++w)
  {
    for (int i = 1; i +w <=n; ++i)
    {
      if ((board[i] != board[i+w]) || (w > 1 && arr[i+1][i+w-1] == 0))
        arr[i][i+w] = 0;
      else arr[i][i+w] = 1;
    }
  }
  cin >> m;
  while (m--)
  {
    cin >> s >> e;
    cout << arr[s][e] << '\n';
  }
}