#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n,s,ans;
int num[25];
void run(int k, int val)
{
  if (k == n) {
    if (val == s) ans++;
    return;
  }
  run(k + 1, val);
  run(k + 1, val + num[k]);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  for (int i = 0; i < n; ++i){
    cin >> num[i];
  }
  sort(num, num+n);
  run(0, 0);
  if (s == 0) cout << ans - 1;
  else cout << ans;
}