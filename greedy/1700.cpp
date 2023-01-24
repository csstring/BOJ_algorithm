#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,k,ans;
int board[100];
vector<int> use;
bool useCheck(int i)
{
  for (int cur : use){
    if (cur == board[i]) return true;
  }
  return false;
}
int getelem(int i)
{
  int pos = 0;
  int ret = 0;
  for (int cur : use)
  {
    bool flag = false;
    for (int j = i; j < k; ++j)
    {
      if (cur != board[j]) continue;
      flag = true;
      if (pos < j){
        pos = j;
        ret = cur;
      }
      break;
    }
    if (flag == false) return cur;
  }
  return ret;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i =0; i <k; ++i)
    cin >> board[i];
  for (int i =0; i <k; ++i)
  {
    if (useCheck(i)) continue;
    if (use.size() < n){
      use.push_back(board[i]);
      continue;
    }
    int elem = getelem(i);
    for (int j =0; j < use.size(); ++j)
    {
      if (use[j] != elem) continue;
      use[j] = board[i];
      break;
    }
    ans++;
  }
  cout << ans;
}