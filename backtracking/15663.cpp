#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n,m;
int temp[10];
int arr[10];
bool isused[10];
void run(int k)
{
  if (k == m){
    for (int i = 0; i < m; ++i)
      cout << arr[i] << ' ';
    cout << '\n'; return;
  }
  int cur = 0;
  for (int i = 0; i < n; ++i)
  {
    if (cur == temp[i]) continue;
    if (isused[i] == false)
    {
      isused[i] = true;
      arr[k] = temp[i];
      cur = temp[i];
      run(k + 1);
      isused[i] = false;
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> temp[i];
  sort(temp, temp+n);
  run(0);
}