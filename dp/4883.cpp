#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[100000][3];
int arr[100000][3];
int n,ans;
void init()
{
  for (int i =0; i <n; ++i)
    for (int j =0; j <3; ++j)
      cin >> board[i][j];
  for (int i =0; i <n; ++i)
    fill(arr[i], arr[i] +3, 0);
  arr[0][1] = board[0][1];
  arr[0][0] = 1001;
  arr[0][2] = board[0][1] + board[0][2];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int count = 1;
  while (1)
  {
    cin >> n;
    if (n == 0) break;
    init();
    for (int i = 1; i < n; ++i)
    {
      arr[i][0] = min({arr[i-1][0], arr[i-1][1]}) + board[i][0];
      arr[i][1] = min({arr[i-1][0], arr[i-1][2], arr[i-1][1],arr[i][0]}) + board[i][1];
      arr[i][2] = min({arr[i-1][2], arr[i-1][1], arr[i][1]}) + board[i][2];
    }
    cout << count << ". " << arr[n-1][1] << '\n';
    count++;
  }
}