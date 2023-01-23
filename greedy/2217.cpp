#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[100000];
int val,n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i <n; ++i)
    cin >> arr[i];
  sort(arr, arr+n);
  for (int i = 0; i <n; ++i)
    arr[i] *= (n-i);
  cout << *max_element(arr,arr+n);
}