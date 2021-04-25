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
		int pi=0,ci=0;
		bool b=true;
		for(int i=0;i<n;i++){
			int p,c;
			cin>>p>>c;
			if(p<pi||c<ci||c-ci>p-pi||c>p)
				b=false;
			pi=p,ci=c;
		}
		if(b)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}