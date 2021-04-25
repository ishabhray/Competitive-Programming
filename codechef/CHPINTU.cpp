#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int T;
	cin>>T;
	while(T--){
		int m,n;
		cin>>n>>m;
		int f[n],p[n];
		for(int i=0;i<n;++i)
			cin>>f[i];
		for(int i=0;i<n;++i)
			cin>>p[i];
		int x[m];
		for(int i=0;i<m;i++)
			x[i]=-1;
		for(int i=0;i<n;++i){
			if(x[f[i]-1]==-1)
				x[f[i]-1]=0;
			x[f[i]-1]+=p[i];
		}
		int min=2501;
		for(int i=0;i<m;i++){
			if(x[i]<min&&x[i]!=-1)
				min=x[i];
		}
		cout<<min<<endl;
	}
}