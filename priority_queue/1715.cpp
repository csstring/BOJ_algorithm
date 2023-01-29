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
int n,val,ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i<n; ++i){
    cin >>val;
    pq.push(val);
  }
  while (pq.size()>1)
  {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    pq.push(a+b);
    ans += a+b;
  }
  cout << ans;
}