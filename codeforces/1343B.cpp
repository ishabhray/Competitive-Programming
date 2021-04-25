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
		int n;
		cin>>n;
		if((n/2)%2==0){
			cout<<"YES\n";
			for(int i=0;i<n/2;i++)
				cout<<2*(i+1)<<' ';
			for(int i=0;i<n/2-1;i++)
				cout<<2*i+1<<' ';
			cout<<3*n/2-1<<'\n';
		}
		else
			cout<<"NO\n";
	}
}