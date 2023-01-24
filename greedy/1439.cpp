#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int ans1, ans2,n;
string str;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> str;
  int tmp = 0;
  int size= str.size();
  for (int i =0; i < size; ++i)
  {
    if (str[i] == '0') {
      if (tmp == 0) ans1++;
      tmp++;
    }
    else tmp = 0;
  }
  tmp = 0;
  for (int i =0; i < size; ++i)
  {
    if (str[i] == '1') {
      if (tmp == 0) ans2++;
      tmp++;
    }
    else tmp = 0;
  }
  cout << min(ans1, ans2);
}