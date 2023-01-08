#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k = 0;
  int val;
  cin >> k;
  deque<int> dq;
  for (int i = 0; i < k; ++i){
    cin >> val;
    dq.push_back(val);
  }
  sort(dq.begin(), dq.end());
  for (int nx : dq)
    cout << nx << '\n';
}