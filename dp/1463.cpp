#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[1000001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  arr[1] = 0;
  for (int i =2; i < 1000001; ++i)
  {
    arr[i] = arr[i-1] +1; 
    if (i % 3 == 0) arr[i] = min(arr[i],arr[i/3] + 1);
    if (i%2 == 0) arr[i] = min(arr[i], arr[i/2] +1); 
  }
  int val;
  cin >> val;
  cout << arr[val];
}