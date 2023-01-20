#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
string str;
const int mod = 1000000;
int arr[5001];
int board[5001];
int total,s,tmp;
size_t ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> str;
  s = str.size();
  for (int i =1; i <= s; ++i)
    board[i] = str[i-1] - '0';
  arr[0] = 1;
  for (int i =1; i <= s; ++i)
  {
    if (board[i] > 0) arr[i] = arr[i-1]% mod;
    if (board[i-1] == 1)
        arr[i] = (arr[i] + arr[i-2])% mod;
    if (board[i-1] == 2 && (board[i] >= 0 && board[i] <= 6))
        arr[i] = (arr[i] + arr[i-2])% mod;
  }
  cout << arr[s] % mod;
}