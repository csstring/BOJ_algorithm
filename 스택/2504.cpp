#include <iostream>
#include <string>
#include <iterator>
#include <stack>
#include <algorithm>
using namespace std;
stack<char> st;
string str;
size_t sum, multi;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  multi = 1;
  cin >> str;
  for (int i = 0; i < str.size(); ++i)
  {
    if (str[i] == '(')
    {
      multi *= 2;
      st.push('(');
    }
    else if (str[i] == '[')
    {
      multi *= 3;
      st.push('[');
    }
    else if (str[i] == ')')
    {
      if (st.empty() || st.top() != '(')
      {
        cout << '0';
        return (0);
      }
      if (str[i - 1] == '(')
        sum += multi;
      multi /= 2;
      st.pop();
    }
    else if (str[i] == ']')
    {
      if (st.empty() || st.top() != '[')
      {
        cout << '0';
        return (0);
      }
      if (str[i - 1] == '[')
        sum += multi;
      multi /= 3;
      st.pop();
    }
  }
  if (st.empty())
    cout << sum;
  else
    cout << '0';
}