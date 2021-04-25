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
		int X,N,M;
		cin>>X>>N;
		int a[N];
		for(int i=0;i<N;i++)
			cin>>a[i];
		cin>>M;
		int b[M];
		for(int i=0;i<M;i++)
			cin>>b[i];
		int c=0;
		for(int i=0;i<=M-N;i++){
			int x;
			for(int j=0;j<N;j++){
				if(j==0)
					x=a[j]-b[i+j];
				else if(b[i+j]+x!=a[j]){
					x=X+1;
					break;
				}
			}
			//cout<<x<<'\n';
			if(abs(x)<=X)
				c++;
		}
		cout<<c<<'\n';
	}
}