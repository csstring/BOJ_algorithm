#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n,m;
int temp[10];
int arr[10];
void run(int k)
{
  if (k == m){
    for (int i = 0; i < m; ++i)
      cout << arr[i] << ' ';
    cout << '\n'; return;
  }
  for (int i = 0; i < n; ++i)
  {
    if (temp[i] < arr[k == 0 ? 0 : k - 1]) continue;
    arr[k] = temp[i];
    run(k + 1);
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