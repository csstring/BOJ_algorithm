#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n,m;
int arr[10];
void run(int k)
{
  if (k == m)
  {
    for (int i = 0; i < m; ++i)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  int st = (k != 0 ? arr[k - 1] : 1);
  for (int i = st; i <= n; ++i){
    arr[k] = i;
    run(k+1);
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  run(0);
}