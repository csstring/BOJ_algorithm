#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[101];
int d[10001];
size_t n,k,val,ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <=n; ++i)
    cin >> arr[i];
  d[0] =1;
  for (int i = 1; i <=n; ++i){
    for (int j = arr[i]; j <=k; ++j)
    {
      d[j] += d[j - arr[i]];
    }
  }
  cout << d[k];
}