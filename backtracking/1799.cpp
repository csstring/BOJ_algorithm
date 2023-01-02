#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
bool vis2[30];//x-y+n+1
int board[12][12];
int n;
stack<int> st;
void run(int k, int ans)
{
  if (k == 2 * n - 1){
    if (st.top() < ans) st.push(ans);
    return;
  }
  bool flag = false;
  if (k < n)
  {
    int y = 0;
    for (int x = k; x >= 0; --x, ++y)
    {
      if (board[x][y] == 0 || vis2[x-y+n+1]) continue;
      flag = true;
      vis2[x-y+n+1] = true;
      run(k+1,ans + 1);
      vis2[x-y+n+1] = false;
    }
  }
  else
  {
    int x = n - 1;
    for (int y = k - n + 1; y <= n - 1; ++y, --x)
    {
      if (board[x][y] == 0 || vis2[x-y+n+1]) continue;
      flag = true;
      vis2[x-y+n+1] = true;
      run(k+1,ans + 1);
      vis2[x-y+n+1] = false;
    }
  }
  if (!flag)
    run(k+1,ans);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      cin >> board[i][j];
    }
  }
  st.push(0);
  run(0,ans);
  cout << st.top();
}