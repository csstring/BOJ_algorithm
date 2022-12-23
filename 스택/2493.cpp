#include <iostream>
#include <string>
#include <iterator>
#include <stack>
using namespace std;
int c, val, max_val;
stack<pair<int, int> > st;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  st.push({1000000001,0});
  cin >> c;
  for (int i = 1; i < c + 1; ++i)
  {
    cin >> val;
    while (st.top().first < val)
      st.pop();
    cout << st.top().second << ' ';
    st.push({val, i});
  }
}