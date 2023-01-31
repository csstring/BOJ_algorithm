#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int b[41];
int n,st,en,val;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =1; i <=n; ++i){
    cin >> val;
    b[i] = b[i-1] + val;
  }
  
}