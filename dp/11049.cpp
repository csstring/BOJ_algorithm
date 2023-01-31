#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
vector<pair<int,int>>v;
int arr[501][501];
int n,r,c;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  v.push_back({0,0});
  for (int i =0; i <n; ++i){
    cin >>r >>c;
    v.push_back({r,c});
  }
  for (int i =1; i <n; ++i)
  {
    for (int j = 1; i +j <=n; ++j)
    {
      arr[j][j+i] = INT32_MAX;
      for (int k =j; k <= j+i; ++k)
      {
        arr[j][i+j] = min(arr[j][i+j], arr[j][k]+arr[k+1][i+j] +v[j].first*v[k].second*v[i+j].second);
      }
    }
  }
  cout << arr[1][n];
}
