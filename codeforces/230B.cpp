#include <bits/stdc++.h>
using namespace std;
bool f[1000000000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		int sn=sqrt(n);
		if((long long)sn*sn==n){
			bool b=true;
			if(n==1)
				b=false;
			int ssn=sqrt(sn);
			for(int i=2;i<=ssn;i++)
				if(sn%i==0)
					b=false;
			if(b)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else
			cout<<"NO\n";
	}
}