#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int arr[10];
int temp[10];
int n,m;
set<int> s;
void run(int k)
{
  if (k == m)
  {
    for (int i = 0; i < m; ++i)
      cout << arr[i] << ' ';
    cout << '\n'; return;
  }
  for (int i = 0; i < n; ++i)
  {
    arr[k] = temp[i];
    run(k + 1); 
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int index = 0;
  int val = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i){
    cin >> val;
    s.insert(val);
  }
  for (auto nx : s){
    temp[index] = nx; index++;
  }
  n = index;
  run(0);
}