#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
vector<pair<int,int>> b;
int n,s,e;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i){
    cin >> s >>e;
    b.push_back({s,e});
  }
  sort(b.begin(), b.end());
  pq.push(0);
  for (pair<int,int> cur : b)
  {
    if (pq.top() <= cur.first) pq.pop();
    pq.push(cur.second);
  }
  cout << pq.size();
}