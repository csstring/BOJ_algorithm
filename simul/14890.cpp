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
vector<int> v;
bool run()
{
  int lsize = 1;
  for (int tmp =0; tmp < n-1; ++tmp)
  {
    if (abs(v[tmp] - v[tmp+1]) > 1) return false;
    if (v[tmp] == v[tmp+1])
      lsize++;
    else if (v[tmp] < v[tmp+1])
    {
      if (lsize < l) return false;
      lsize = 1;
    }
    else if (v[tmp] > v[tmp+1])
    {
      lsize = 0;
      for (int j = tmp + 1; j < n; ++j){
        if (v[j] == v[tmp+1]) lsize++;
        else break;
        if (lsize == l) break;
      }
      if (lsize < l) return false;
      tmp += lsize-1;
      lsize = 0;
    }
  }
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
      v[j] = board[i][j];
    }
    ans += run();
  }
  for (int j = 0; j < n; ++j){
    for (int i =0; i <n; ++i){
      v[i] = board[i][j];
    }
    ans += run();
  }
  cout << ans;
}