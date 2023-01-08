#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,k;
vector<int> c;
int arr[14];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  for (int i = 0; i < 4; ++i){
    cin >> k;
    for (int j =0; j <k; ++j){
      c.push_back(i);
    }
  }
  int mx = INT32_MIN;
  int mn = INT32_MAX;
  do {
    int tmp = arr[0];
    for (int i = 1; i <n; ++i)
    {
      if (c[i-1] == 0) 
        tmp += arr[i];
      if (c[i-1] == 1)  tmp -= arr[i];
      if (c[i-1] == 2){
        tmp *= arr[i];
      }
      if (c[i-1] == 3){
        if (tmp < 0){
          tmp = abs(tmp) / arr[i];
          tmp *= -1;
        }
        else{
          tmp /= arr[i];
        }
      }
    }
      mx = max(mx, tmp);
      mn = min(mn, tmp);
  }while(next_permutation(c.begin(), c.end()));
  cout << mx << '\n' << mn;
}