#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n;
vector<size_t> v;
string str1,str2;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >>n;
  for (int i = 0 ; i < n ; ++i)
  {
    cin >> str1;
    int s = 0;
    int e = str1.size() -1;
    while (s < e)
    {
      swap(str1[s], str1[e]);
      s++; e--;
    }
    v.push_back(stol(str1));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i)
    cout << v[i] << '\n';
}