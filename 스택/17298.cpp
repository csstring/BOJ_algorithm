#include <iostream>
#include <string>
#include <iterator>
#include <stack>
using namespace std;
stack<pair<int,int>> st;
int c, val, arr[1000005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> c;
  st.push({1000001,0});
  fill(arr + 1, arr + c + 1, -1);
  for (int i = 1; i < c + 1; ++i)
  {
    cin >> val;
    while (st.size() > 1 && st.top().first < val)
    {
      arr[st.top().second] = val;
      st.pop();
    }
    st.push({val, i});
  }
  for (int i = 1; i < c + 1; ++i)
    cout << arr[i] << ' ';
}