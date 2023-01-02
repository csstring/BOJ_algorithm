#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int k;
int arr[15];
vector<int> v;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1)
  {
    cin >> k;
    if (k == 0) break;
    v = {};
    for (int i = 0; i < k; ++i){
      if (i < 6) v.push_back(0);
      else v.push_back(1);
      cin >> arr[i];
    }
    do{
      for (int i = 0; i < k; ++i){
        if (v[i] == 0) cout << arr[i] << ' ';
      }
      cout << '\n';
    }while(next_permutation(v.begin(), v.end()));
    cout << '\n';
  }
}