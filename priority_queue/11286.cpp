#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,val;
struct cmp
{
  bool operator()(int a, int b)
  {
    if (abs(a) != abs(b)){
      return abs(a) > abs(b);
    }
    return a >0 && b <0;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int,vector<int>,cmp> pq;
  cin >> n;
  while (n--)
  {
    cin >> val;
    if (val == 0){
      if (pq.empty()) cout << 0 << '\n';
      else{
        cout << pq.top() << '\n';
        pq.pop();
      }
    }
    else pq.push(val);
  }
}