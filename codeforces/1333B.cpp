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
		int a[n],c[n]={0},c0=0,c1=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(c0!=0&&c1!=0)
				c[i]=3;
			else if(c0!=0)
				c[i]=1;
			else if(c1!=0)
				c[i]=2;
			if(a[i]==1)
				c1=1;
			else if(a[i]==-1)
				c0=1;
		}
		bool b=true;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(b){
				if(c[i]==3||a[i]==x)
					continue;
				if(a[i]>x && c[i]!=1)
					b=false;
				else if(a[i]<x && c[i]!=2)
					b=false;
			}
		}
		if(b)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}