#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int> >v;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			v.push_back({x,i});
		}
		sort(v.begin(),v.end());
		int c=n,s=0;
		long long int f=0;
		for(int i=0;i<n;i++){
			//cout<<c<<' '<<s<<' '<<f<<'\n';
			if(v[i].second<=c)
				f+=(long long int)(v[i].first-s)*c,c=v[i].second,s=v[i].first;
		}
		cout<<f<<'\n';
	}
}
