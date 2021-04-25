#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<pair<int,int> >v;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.pb({x,y});
	}
	sort(v.begin(),v.end());
	int xmax=
	for(auto a:v)
		cout<<a.f<<' '<<a.s<<'\n';
}