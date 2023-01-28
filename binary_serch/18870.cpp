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
int b[1000000];
vector<int> v;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i){
    cin >> b[i];
    v.push_back(b[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i =0; i<n; ++i)
  {
    cout << lower_bound(v.begin(), v.end(), b[i]) - v.begin() << ' ';
  }
}