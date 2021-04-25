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
		int n,x;
		cin>>n>>x;
		set<int>s;
		for(int i=0;i<n;i++){
			int c;
			cin>>c;
			s.insert(c);
		}
		for(auto it=s.begin();it!=s.end();it++){
			if(*it<=x+1)
				x++;
		}
		cout<<x<<'\n';
	}
}