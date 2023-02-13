#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
vector<pair<int,int>> v;
int w,n,m,p;
size_t ans;
using namespace std;
bool ft_cmp(pair<int,int> a, pair<int,int> b)
{
	return a.first > b.first;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> w >>n;
	for (int i =0; i <n; ++i)
	{
		cin >>m >>p;
		v.push_back({p,m});
	}
	sort(v.begin(), v.end(),ft_cmp);
	return 0;
}