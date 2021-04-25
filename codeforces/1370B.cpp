#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
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

	int t=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n*2];
		vi e,o;
		for(int i=0;i<2*n;i++){
			cin>>a[i];
			if(a[i]%2==0)
				e.pb(i+1);
			else
				o.pb(i+1);
		}
		if(o.empty()){
			for(int i=0;i<2*n-2;i+=2)
				cout<<e[i]<<' '<<e[i+1]<<'\n';
		}
		else if(e.empty()){
			for(int i=0;i<2*n-2;i+=2)
				cout<<o[i]<<' '<<o[i+1]<<'\n';
		}
		else if(e.size()%2==0){
			for(int i=0;i<e.size();i+=2)
				cout<<e[i]<<' '<<e[i+1]<<'\n';
			for(int i=0;i<o.size()-2;i+=2)
				cout<<o[i]<<' '<<o[i+1]<<'\n';
		}
		else{
			for(int i=0;i<e.size()-1;i+=2)
				cout<<e[i]<<' '<<e[i+1]<<'\n';
			for(int i=0;i<o.size()-1;i+=2)
				cout<<o[i]<<' '<<o[i+1]<<'\n';
		}
	}
}