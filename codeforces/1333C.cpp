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

	int n;
	cin>>n;
	int a[n],r[n];
	ll int p[n+1];
	p[0]=0;
	map<ll int,int>m;
	int j=1;
	m[0]=1;
	for(int i=0;i<n;i++)
		r[i]=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		p[i+1]=a[i]+p[i];
		if(m[p[i+1]]==0)
			m[p[i+1]]=i+2;
		else{
			while(j<=m[p[i+1]])
				r[j-1]=i,j++;
			m[p[i+1]]=i+2;
		}
	}
	ll int s=0;
	for(int i=0;i<n;i++)
		s+=r[i]-i;
	cout<<s;
}