#include <iostream>
#include <string>
#include <iterator>
#include <stack>
#include <algorithm>
using namespace std;
int n, total;
string str;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> str;
    stack<char> st;
    for (int j = 0; j < str.size(); ++j)
    {
      if (!st.empty() && st.top() == str[j])
        st.pop();
      else
        st.push(str[j]);
    }
    if (!st.size())
      total++;
  }
  cout << total;
}