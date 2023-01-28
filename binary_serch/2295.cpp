#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[1000];
vector<int> two;
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i) cin >> board[i];
  sort(board, board+n);
  for (int i =0; i <n; ++i){
    for (int j = i; j <n; ++j){
      two.push_back(board[i] + board[j]);
    }
  }
  sort(two.begin(), two.end());
  for (int i = n-1; i >=1; --i){
    for (int j = 0; j <i; ++j){
    if (binary_search(two.begin(), two.end(), board[i]-board[j])){
      cout << board[i];
      return (0);
    }
    }
  }
}