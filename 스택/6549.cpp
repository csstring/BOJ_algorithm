#include <iostream>
#include <string>
#include <iterator>
#include <stack>
#include <vector>
using namespace std;
int n, h, cnt;
size_t max_val, temp;
vector<pair<int,int>> st;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n != 0)
  {
    st.clear(); max_val = 0;
    for (int i = 0; i < n; ++i)
    {
      cin >> h;
      cnt = 1; temp = 0;
      while (st.size() > 0 && st.back().first >= h)
      {
        cnt += st.back().second;
        temp += st.back().second * h;
        st.pop_back();
      }
      temp = 
      st.push_back({h, cnt});
      if (temp > max_val)
        max_val = temp;
    }
    cout << max_val << '\n';
    cin >> n;
  }
}