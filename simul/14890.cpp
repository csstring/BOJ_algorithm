//경사로
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[100][100];
int n,l,ans;
vector<pair<int,int>> v;
bool run()
{
  int lsize = 0;
  int cur = 0;
  for (int i =0; i < n; ++i)
  {
    if (cur == v[i].first)
    {
      lsize++;
      if (lsize >= l && i == n -1)
      {
        for (int j = 0; j < lsize; ++j)
          v[i-j].second++;
      }
    }
    else
    {
      if (lsize >= l)
      {
        for (int j = 1; j <= lsize; ++j)
          v[i-j].second++;
      }
      lsize = 1;
      cur = v[i].first;
    }
  }
  for (int i = 0; i<n; ++i){
   cout << v[i].first << ',' << v[i].second << ' ';
  }
  cout << endl;
  for (int i =0; i < n-1; ++i){
    int cur = v[i].first;
    if (v[i+1].first == cur || v[i+1].second == cur) continue;
    return false;
  }
  for (int i =0; i < n; ++i)
    cout << v[i].first << ' ';
    cout << endl;
  return true;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  v.resize(100);
  cin >> n >>l;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      cin >> board[i][j];
    }
  }
  for (int i = 0; i < n; ++i){
    for (int j =0; j <n; ++j){
      v[j].first = board[i][j];
      v[j].second = board[i][j];
    }
    ans += run();
  }
  for (int j = 0; j < n; ++j){
    for (int i =0; i <n; ++i){
      v[i].first = board[i][j];
      v[i].second = board[i][j];
    }
    ans += run();
  }
  cout << ans;
}