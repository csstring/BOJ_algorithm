#include <iostream>
#include <string>
#include <iterator>
#include <deque>
#include <algorithm>
using namespace std;
string str;
deque<char> st;
int error_flag;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1)
  {
    error_flag = 0;
    str.clear();
    getline(cin, str);
    st.clear();
    if (str == ".")
      return (0);
    for (int i = 0; i < str.size(); ++i)
    {
      if (str[i] == '(' || str[i] == '[')
        st.push_back(str[i]);
      else if (str[i] == ')' || str[i] == ']')
      {
        if (st.empty())
        {
          error_flag = 1;
          break;
        }
        if (str[i] == ')' && st.back() == '(')
          st.pop_back();
        else if (str[i] == ']' && st.back() == '[')
          st.pop_back();
        else
        {
          error_flag = 1;
          break;
        }
      }
    }
    if (st.size() == 0 && error_flag == 0)
      cout << "yes\n";
    else
      cout << "no\n";
  }
}