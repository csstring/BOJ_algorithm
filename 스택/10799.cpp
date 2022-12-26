#include <iostream>
#include <string>
#include <iterator>
#include <stack>
#include <algorithm>
using namespace std;
int n, total, arr[100005], temp;
string str;
stack< pair<char, int>> st;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  int size = str.size();
  for (int i = 0; i < size ; ++i)
  {
    temp = 0;
    if (str[i] == '(')
      st.push({'(', i});
    else
    {
      if (st.top().second + 1 == i)
      {
        arr[i - 1] = 1;
        arr[i] = 1;
      }
      else
      {
        for (int j = st.top().second; j != i; ++j)
        {
          if (arr[j] == 1)
            temp++;
        }
        total += temp / 2 + 1;
      }
      st.pop();
    }
  }
  cout << total;
}