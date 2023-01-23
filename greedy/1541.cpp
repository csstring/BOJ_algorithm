#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
string str;
int ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> str;
  bool flag = true;
  int tmp =0;
  for (int i = 0; i < str.size(); ++i)
  {
    if (str[i] == '-'|| str[i] == '+') {
      if (flag == false) ans -= tmp;
      else ans += tmp;
      if (str[i] == '-') flag = false;
      tmp = 0;
    }
    else{
      tmp = tmp * 10 + (str[i] - '0');
    }
    if (i == str.size() - 1){
      if (flag == false) ans -= tmp;
      else ans += tmp;
    }
  }
  cout << ans;
}