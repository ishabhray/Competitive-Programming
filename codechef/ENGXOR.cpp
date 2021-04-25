#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		int e=0,o=0;
		for(int i=0;i<n;i++){
			int b,c=0;
			cin>>b;
			for(int k=31;k>=0;k--)
				if((b>>k)&1)
					c++;
			if(c%2==0)
				e++;
			else
				o++;
		}
		for(int i=0;i<q;i++){
			int p;
			cin>>p;
			int c=0;
			for(int k=31;k>=0;k--)
				if((p>>k)&1)
					c++;
			if(c%2==0)
				cout<<e<<' '<<o<<'\n';
			else
				cout<<o<<' '<<e<<'\n';			
		}
		
	}
}