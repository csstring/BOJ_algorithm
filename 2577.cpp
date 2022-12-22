#include <iostream>
#include <string>

using namespace std;
string s[4];
size_t val;
int arr[10];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 3; ++i)
    getline(cin, s[i]);
  val = stol(s[0]) * stol(s[1]) * stol(s[2]);
  s[3] = to_string(val);
  for (string::iterator it = s[3].begin(); it != s[3].end(); ++it)
  {
    arr[*it - 48]++;
  }
  for (int i = 0; i < 10; ++i)
    cout << arr[i] << '\n';
}