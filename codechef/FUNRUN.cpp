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
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		int maxa=0,maxb=0;
		for(int i=0;i<n;i++){
			if(a[i]>maxa)
				maxa=a[i];
			if(b[i]>maxb)
				maxb=b[i];
		}
		if(maxa==maxb)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}