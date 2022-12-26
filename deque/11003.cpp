#include <iostream>
#include <string>
#include <iterator>
#include <deque>
using namespace std;
int n, l, val;
deque< pair<int,int> > dq;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> l;
  for (int i = 1; i < n + 1; ++i)
  {
    cin >> val;
    while (!dq.empty() && dq.back().second >= val)
      dq.pop_back();
    dq.push_back({i, val});
    if (dq.front().first < i - l + 1)
      dq.pop_front();
    cout << dq.front().second << ' ';
  }
}