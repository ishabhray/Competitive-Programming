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
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i!=0)
				a[i]+=a[i-1];
		}
		vector<pair<int,int> >v;
		for(int i=1;i<n;i++){
			if(a[i-1]==i*(i+1)/2&&a[n-1]-a[i-1]==(n-i)*(n-i+1)/2)
				v.push_back({i,n-i});
		}
		cout<<v.size()<<'\n';
		for(auto it=v.begin();it!=v.end();it++)
			cout<<it->first<<' '<<it->second<<'\n';
	}
}