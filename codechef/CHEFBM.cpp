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

	int n,m,p;
	cin>>n>>m>>p;
	vector<int> cost(n,m-1);
	vector< pair<int,int> > v;
	for(int i=0;i<p;++i){
		int x,y;
		cin>>x>>y;
		v.push_back( make_pair(x,y));
	}
	sort(v.rbegin(),v.rend());
	int max=1,c=0;
	for(int i=0;i<p;++i){
		int x=v[i].first-1, y=v[i].second;
		c++;
		if(cost[x]==-1)
			continue;
		if(c>max&&y!=m){
			cost[x]=-1;
			c=0,max=1;
			continue;
		}

		if(i==p-1){
			if(y==m)
				cost[x]+=c;
			else if(y==1)
				cost[x]-=c;
			break;
		}
		else{
			if(v[i+1].first-1!=x){
				if(y==m)
					cost[x]+=c;
				else if(y==1)
					cost[x]-=c;
				c=0,max=1;
			}
			else if(v[i+1].second!=y){
				if(y==m)
					cost[x]+=c;
				else if(y==1)
					cost[x]-=c;
				max+=c,c=0;
			}
		}
	}
	for(auto i=cost.begin(); i!=cost.end(); ++i){
		cout<<*i<<'\n';
	}

	return 0;
}