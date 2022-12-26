#include <iostream>
#include <string>
#include <iterator>
#include <stack>
#include <algorithm>
using namespace std;
int n, temp;
string str;
size_t total;
stack<pair<int,int>> st;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  for (int i = 0; i < str.size(); ++i)
  {
    if (str[i] == '(')
      st.push({i, 0});
    else
    {
      if (st.top().first == i - 1)
      {
        st.pop();
        if (!st.empty())
          st.top().second++;
      }
      else
      {
        temp = st.top().second;
        total += temp + 1;
        st.pop();
        if (!st.empty())
          st.top().second += temp;
      }
    }
  }
  cout << total;
}