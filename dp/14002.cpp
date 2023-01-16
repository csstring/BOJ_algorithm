#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[1001];
int Count[1001];
int vis[1001];
int n,ans,tmp;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =1; i <=n; ++i)
    cin >> board[i];
  fill(Count, Count +1001,1);
  for (int i =1; i <= n; ++i){
    for (int j =1; j < i; ++j){
      if (board[j] >= board[i]) continue;
      if (Count[j] + 1 > Count[i])
      {
        Count[i] = Count[j] + 1;
        vis[i] = j;
      }
    }
  }
  stack<int> st;
  for (int i =1;i <=n; ++i)
  {
    if (Count[i] > ans)
    {
      ans = Count[i];
      tmp = i;
    }
  }
  while (tmp != 0)
  {
    st.push(board[tmp]);
    tmp = vis[tmp];
  }
  cout << ans << '\n';
  while (!st.empty())
  {
    cout << st.top()<< ' ';
    st.pop();
  }
}