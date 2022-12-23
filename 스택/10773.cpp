#include <iostream>
#include <string>
#include <iterator>
#include <stack>
using namespace std;
int k, val;
size_t total;
stack<int> st;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k;
  for (int i = 0; i < k; ++i)
  {
    cin >> val;
    if (val == 0)
      st.pop();
    else
      st.push(val); 
  }
    while (st.size())
    {
      total += st.top();
      st.pop();
    }
  cout << total;
}