#include <bits/stdc++.h>
using namespace std;
#define pb(r,c) push_back(make_pair((r),(c)))
int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		vector < pair< int,int > > v;
		int r,c,i=0;
		cin>>r>>c;
		if(r!=1 or c!=1){
			r=c=(r+c)/2;
			v.pb(r,c);
			i=2;
			r=c=1;
			v.pb(r,c);
		}
		int k=1;
		while(true){
			r++;
			c++;
			i++;
			k++;
			v.pb(r,c);
			if(k==8)
				break;
			int x=2*k-1,y=1;
			if(x>=8)
				x=8,y=2*k-8;
			v.pb(x,y);
			v.pb(y,x);
			v.pb(r,c);
			i+=3;
		}
		cout<<i<<endl;
		for(auto it=v.begin();it!=v.end();++it)
			cout<<it->first<<' '<<it->second<<endl;

	}
}