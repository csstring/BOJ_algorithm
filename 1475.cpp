#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int arr[10],max_val ,temp;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  getline(cin, s);
  for (string::iterator it = s.begin(); it != s.end(); ++it)
  {
    arr[*it - 48]++;
  }
  temp = arr[6] + arr[9];
  if (temp % 2)
    temp++;
  temp = temp / 2;
  arr[6] = temp;
  arr[9] = temp;
  cout << *max_element(arr, arr+10);
}