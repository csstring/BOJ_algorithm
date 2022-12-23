#include <iostream>
#include <string>
#include <iterator>
#include <stack>
using namespace std;
stack<pair<int,int>> st;
size_t val, c, total;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> c;
  st.push({1000000001, 0});
  for (int i = 1; i < c + 1; ++i)
  {
    cin >> val;
    while (st.top().first <= val)
      st.pop();
    total += st.size() - 1;
    st.push({val, i});
  }
  cout << total;
}