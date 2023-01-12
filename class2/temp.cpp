#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <set>
using namespace std;
size_t ans,n,m,total,val1,val2,a,b,c;
size_t arr[3];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  while (1)
  {
    cin >> arr[0] >> arr[1] >>arr[2];
    if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0 ) break;
    sort(arr, arr+3);
    if (arr[2]*arr[2] == (arr[0]*arr[0] + arr[1]*arr[1])) cout << "right\n";
    else cout << "wrong\n";
  }
}