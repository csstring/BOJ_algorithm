#include <iostream>
#include <string>
#include <iterator>
#include <stack>
#include <algorithm>
using namespace std;
int n, vaild;
string str;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> str;
    vaild = 0;
    stack<char> st;
    for (int j = 0; j < str.size(); ++j)
    {
      if (str[j] == '(')
        st.push('(');
      else
      {
        if (st.empty())
        {
          vaild = 1;
          break;
        }
        else
          st.pop();
      }
    }
    if (st.empty() && vaild == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}