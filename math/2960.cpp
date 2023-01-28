#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
vector<bool> v(2001,true);
int n,k,ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>k;
  for (int i = 2; i <= n; ++i)
  {
    if (v[i]==false) continue;
    v[i] = false; ans++;
    if (ans == k){
      cout << i;
      break;
    }
    for (int j = i*i; j <=n; j += i)
    {
      if (v[j]==false) continue;
      v[j] = false;
      ans++;
      if (ans == k){
        cout << j;
        break;
      }
    }
  }
}