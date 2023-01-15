#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
vector<string> v;
string str;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> str;
  for (int i =0; i < str.size(); ++i)
  {
    string tmp;
    tmp.assign(str.begin()+i, str.end());
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i)
  {
    cout << v[i] << '\n';
  }
}