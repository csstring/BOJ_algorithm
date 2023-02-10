#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
size_t ans;
int n,s,midn,val;
vector<int> a,b;
void inita()
{
  for (int i = 1; i <= midn; ++i)
  {
    cin >> val;
    int s = a.size();
    for (int j =0; j < s; ++j)
      a.push_back(a[j]+ val);
    a.push_back(val);
  }
}
void initb()
{
  for (int i = midn+1; i <= n; ++i)
  {
    cin >> val;
    int s = b.size();
    for (int j =0; j < s; ++j)
      b.push_back(b[j]+ val);
    b.push_back(val);
  }
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
  cin >> n >> s;
  midn = n/2;
  inita(); initb();
  sort(b.begin(), b.end());
  sort(a.begin(), a.end());
  ans += (upper_bound(b.begin(), b.end(), s) - lower_bound(b.begin(), b.end(), s));
  ans += (upper_bound(a.begin(), a.end(), s) - lower_bound(a.begin(), a.end(), s));
  for (int i=0; i < a.size();++i)
    ans += (upper_bound(b.begin(), b.end(), s-a[i]) - lower_bound(b.begin(), b.end(), s-a[i]));
  cout << ans;
}