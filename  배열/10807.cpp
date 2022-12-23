#include <iostream>

using namespace std;
int arr[205], Count, find_val, temp;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> Count;
  for (int i = 0; i < Count; ++i)
  {
    cin >> temp;
    arr[temp + 100]++;
  }
  cin >> find_val;
  cout << arr[find_val + 100];
}