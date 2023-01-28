#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int nt,mt;
int n[500000], m[500000];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> nt;
  for (int i =0; i< nt; ++i) cin >> n[i];
  sort(n, n+nt);
  cin >> mt;
  for (int i =0; i <mt; ++i) cin >> m[i];
  for (int i =0; i <mt; ++i)
    cout << upper_bound(n,n+nt, m[i]) -lower_bound(n,n+nt,m[i]) << ' ';
}