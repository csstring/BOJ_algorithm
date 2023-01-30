#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
ssize_t n;
ssize_t b[5004];
ssize_t arr[3] = {INT32_MAX,INT32_MAX,INT32_MAX};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n ; ++i) cin >> b[i];
  sort(b, b + n);
  for (int i =0; i <n-1; ++i){
    for (int j =i+1; j<n; ++j)
    {
      int idx = lower_bound(b, b+n, -(b[i] + b[j])) - b;
      for (int k = -1; k <=1; ++k)
      {
        if (b[idx +k] == b[i] || b[idx+k] == b[j]) continue;
        if (idx +k < 0 || idx+k >= n) continue;
        if (abs(arr[0] + arr[1] + arr[2]) > abs(b[i]+b[j]+b[idx+k]))
          tie(arr[0], arr[1],arr[2]) = {b[i],b[j],b[idx+k]};
      }
    }
  }
  sort(arr,arr+3);
  cout << arr[0] << ' '<< arr[1] << ' ' << arr[2];
}