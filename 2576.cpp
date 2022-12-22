#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
vector<int> v;
int val;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 7; ++i)
  {
    cin >> val;
    if (val % 2)
      v.push_back(val);
  }
  if (v.size() == 0)
  {
    cout << "-1";
    return 0;
  }
  val = 0;
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    val += *it;
  cout << val << '\n';
  cout << *min_element(v.begin(), v.end()) << '\n';
}