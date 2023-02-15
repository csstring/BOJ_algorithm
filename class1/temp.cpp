#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int ans,n,total,val1,val2;
char val;
int arr[30];
string str;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> str;
  fill(arr,arr+26,-1);
  for (int i=0; i <str.size(); ++i){
    arr[toupper(str[i]) - 65]++;
  }
  for (int i=0; i < 26; ++i)
  {
    if (arr[i] == 0) continue;
    if (arr[i] > ans) {
      val1 = i;
      ans = arr[i];
    } 
  }
  sort(arr,arr+26,greater<int>());
  if (arr[0] == arr[1]) cout << '?';
  else cout << (char)(val1 + 65);
}