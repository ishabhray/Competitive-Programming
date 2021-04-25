#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

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
		int n,k;
		cin>>n>>k;
		int p[n];
		map<int,int>m;
		for(int i=0;i<n;i++){
			cin>>p[i];
			m[p[i]]=i;
		}
		vv<ii >v;
		vv<pair<int,pair<int,int> > >v1;
		for(int i=0;i<n;i++){
			if(p[i]==i+1||m[m[i+1]+1]==i)
				continue;
			int l=i,r=m[i+1],mid=m[r+1];
			p[r]=p[mid];
			p[mid]=p[l];
			p[l]=i+1;
			m[p[r]]=r;
			m[p[l]]=l;
			m[p[mid]]=mid;
			v1.pb({l+1,{mid+1,r+1}});
		}
		for(int i=0;i<n;i++){
			if(p[i]==i+1)
				continue;
			if(m[m[i+1]+1]==i&&find(v.begin(),v.end(),mp(m[i+1]+1,i+1))==v.end()&&find(v.begin(),v.end(),mp(i+1,m[i+1]+1))==v.end())
				v.pb({i+1,m[i+1]+1});
		}
		//for(auto a:v)
		//	cout<<a.ff<<' '<<a.ss<<'\n';
		if(v.size()%2!=0)
			cout<<"-1\n";
		else{
			
			for(auto it=v.begin();it!=v.end();it+=2){
				v1.pb({it->ff,{(it+1)->ff,it->ss}});
				v1.pb({(it+1)->ff,{it->ss,(it+1)->ss}});
			}
			cout<<v1.size()<<'\n';
			for(auto a:v1)
				cout<<a.ff<<' '<<a.ss.ff<<' '<<a.ss.ss<<'\n';
		}
	}
}