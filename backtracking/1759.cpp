//암호 만들기
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int l,c;
char arr[20];
vector<int> v;

bool check(void)
{
  int one = 0;
  int two = 0;
  for (int i = 0; i < c; ++i)
  {
    bool flag = false;
    if (v[i] == 0)
    {
      for (char a : {'a','e','i','o','u'})
      {
        if (arr[i] == a) {
          one++; flag = true;
          break;
        }
      }
      if (!flag) two++;
    }
  }
  if (one >= 1 && two >=2) return true;
  return false;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> l >> c;
  for (int i = 0; i < c; ++i){
    cin >> arr[i];
    if (i >= l) v.push_back(1);
    else v.push_back(0);
  }
  sort(arr, arr + c);
  do {
    if (!check()) continue;
    for (int i = 0; i < c; ++i){
      if (v[i] == 0) cout << arr[i];
    }
    cout << '\n';
  }while (next_permutation(v.begin(), v.end())); 
}