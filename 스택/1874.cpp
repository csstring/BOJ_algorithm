#include <iostream>
#include <string>
#include <iterator>
#include <stack>
#include <vector>
using namespace std;
int n, val;
stack<int> st;
vector<string> v;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int stick = 0;
  cin >> n;
  for (int i = 1; i < n + 1; ++i)
  {
    cin >> val;
    if (val > stick)
    {
      while (val > stick)
      {
        stick++;
        v.push_back("+\n");
        st.push(stick);
      } 
    }
    if (st.top() == val)
    {
      v.push_back("-\n");
      st.pop();
    }
    else
    {
      cout << "NO";
      return (0);
    }
  }
  for (vector<string>::iterator it = v.begin(); it != v.end(); ++it)
    cout << *it;
}