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
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=0;i<n;i++){
			map<int,int>cnt;
			for(int j=0;j<k;j++){
				int x;
				cin>>x;
				cnt[x]++;
			}
			int max=0,ans=0;
			for(int j=1;j<=m;j++)
				if(cnt[j]>=max)
					ans=j,max=cnt[j];
			cout<<ans<<' ';
		}
		cout<<'\n';
	}
}