//스타트와 링크
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
vector<int> team1;
vector<int> team2;
vector<int> all;
int n,ans;
int board[20][20];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int half = n/2;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      cin >> board[i][j];
    }
  }
  all.assign(n,0);
  fill(all.begin() + half, all.end(),1);
  ans = INT32_MAX;
  do{
    int tans1 = 0;
    int tans2 = 0;
    int mn;
    for (int i = 0; i < n; ++i){
      for (int j =0; j < n; ++j){
        if (all[i] != all[j]) continue;
        if (all[i]) tans1 += board[i][j];
        else tans2 += board[i][j];
      }
    }
    mn = abs(tans1 - tans2);
    ans = min(ans, mn);
  }while (next_permutation(all.begin(), all.end()));
  cout << ans;
}