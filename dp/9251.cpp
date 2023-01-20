//LCS
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
string str1,str2;
int arr[1001][1001];
int ans,tmp;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> str1 >> str2;
  int size1 = str1.size();
  int size2 = str2.size();
  for (int i =1; i <= size1; ++i){
    for (int j =1; j <= size2; ++j){
      if (str1[i-1] == str2[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
      else arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
    }
  }
  cout << arr[size1][size2];
}