#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t arr[41];
stack<int> st;
int board[41];
int n,m,ans,tmp,val;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 2;
  for (int i =3;i <=40; ++i){
    arr[i] = arr[i-2] + arr[i-1];
  }
  cin >> n >> m;
  while (m--)
  {
    cin >> val;
    board[val] = 1;
  }
  for (int i =1; i <=n; ++i)
  {
    if (board[i] == 1)
    {
      st.push(arr[tmp]);
      tmp = 0;
    }
    else if (board[i] == 0)
      tmp++;
    if (i == n)
      st.push(arr[tmp]);
  }
  ans =1;
  while (!st.empty())
  {
    ans *= st.top(); 
    st.pop();
  }
  cout << ans;
}
