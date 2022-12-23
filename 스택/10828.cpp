#include <iostream>
#include <string>
#include <iterator>
#include <stack>
using namespace std;
int n, val;
stack<int> st;
string cmd;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> cmd;
    if (cmd == "push")
      cin >> val;
    if (cmd == "push")
    {
      st.push(val);
    }
    else if (cmd == "pop")
    {
      if (st.size() == 0)
        cout << "-1\n";
      else
      {
        cout << st.top() << '\n';
        st.pop();
      }
    }
    else if (cmd == "size")
    {
      cout << st.size() << '\n';
    }
    else if (cmd == "empty")
    {
      if (st.size() == 0)
        cout << "1\n";
      else
        cout << "0\n";
    }
    else
    {
      if (st.size() == 0)
        cout << "-1\n";
      else
      {
        cout << st.top() << '\n';
      } 
    }
  }
}