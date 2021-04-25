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
		int n,q;
		cin>>n>>q;
		vector<int>v;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<q;++i){
			int x;
			cin>>x;
			auto it=lower_bound(v.begin(),v.end(),x);
			cout<<*it<<' ';
			int cnt=it-v.begin()-1;
			while(cnt>0){
				cout<<cnt<<' ';
				int y=x-*(it-1);
				cout<<y<<'\n';
				if(y<=cnt){
					it--;
					cnt-=(y+1);
				}
			}
			cout<<v.end()-it<<'\n';
		}
	}
}