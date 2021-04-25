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
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int c=a[0]>0,p=a[0];
		ll s=0;
		for(int i=1;i<n;i++){
			if(c!=a[i]>0)
				s+=p,p=a[i],c=!c;
			else
				p=(a[i]>p)?a[i]:p;
		}
		s+=p;
		cout<<s<<'\n';
	}
}