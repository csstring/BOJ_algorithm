#include <iostream>
#include <string>
using namespace std;
string s;
int val[26];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  getline(cin, s);
  for (string::iterator it = s.begin(); it != s.end(); ++it)
  {
    val[*it - 97]++;
  }
  for (int i = 0; i < 26; ++i)
    cout << val[i] << " ";
}