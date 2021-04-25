#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
		int p=0;
		ll s=0;
		for(int i=0;i<q;i++){
			int f,d;
			cin>>f>>d;
			s+=abs(f-p)+abs(d-f);
			p=d;
		}
		cout<<s<<'\n';
	}
}