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

	int n,m,k;
	cin>>n>>m>>k;
	int a[m];
	for(int i=0;i<m;i++)
		cin>>a[i];
	int x,f=0;
	cin>>x;
	for(int i=0;i<m;i++){
		int y=x^a[i],z=0;
		for(int j=n-1;j>=0;j--)
			if((y>>j)&1)
				z++;
		if(z<=k)
			f++;
	}
	cout<<f;
}