#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t board[10001];
size_t arr[10001][3];
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i=1; i <= n; ++i)
    cin >> board[i];
  arr[1][1] = board[1];
  for (int i =2; i <= n;++i)
  {
    arr[i][0] = *max_element(arr[i-1],arr[i-1] + 3);
    arr[i][1] = arr[i-1][0] + board[i];
    arr[i][2] = arr[i-1][1] + board[i]; 
  }
  cout << *max_element(arr[n], arr[n] + 3);
}