#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
int n, m;
int arr[10];
int isused[10];
void func(int k)
{
  if (k == m)
  {
    for (int i = 0; i < m; ++i)
      cout << arr[i] << ' ';
    cout << '\n'; return;
  }
  int st = k -1;
  if (k == 0) st = 0;
  for (int i = 1; i <=n; ++i){
    if (isused[i] == false && i > arr[st])
    {
      isused[i] = true;
      arr[k] = i;
      func(k + 1);
      isused[i] = false;
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  func(0);
}*/
int n,m;
vector<int> v;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) v.push_back(i < m ? 0 : 1);
  do{
    for (int i = 0; i < n; ++i)
      if (v[i] == 0) cout << i + 1<< ' ';
    cout << '\n';
  }while (next_permutation(v.begin(), v.end()));
}