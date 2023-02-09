#include <iostream>
using namespace std;
int b[4][100000];
int s[4][100000];
int n;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i<3; ++i){
    for (int j =0; j<n;++j){
      cin >> b[i][j];
      s[i][j] = b[i][j];
    }
  }
  for (int i =0; i <n; ++i) {
    b[3][i] = b[0][i] + b[1][i] + b[2][i];
    s[3][i] = b[3][i];
  }
  for (int i=0; i <4; ++i) sort(s[i],s[i]+n);
  for (int k =0; k<4;++k)
  {
    for (int i =0; i <n; ++i)
    {
      int idx = upper_bound(s[k],s[k]+n,b[k][i]) - s[k];
      cout << n-idx +1 << ' ';
    }
    cout << '\n';
  }
}