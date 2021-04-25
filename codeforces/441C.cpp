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

	int n,m,r;
	cin>>n>>m>>r;
	vv<ii >v;
	for(int k=0;k<n;k++){
		if(k%2==0){
			for(int i=0;i<m;i++)
				v.pb({k+1,i+1});
		}
		else{
			for(int i=m-1;i>=0;i--)
				v.pb({k+1,i+1});
		}
	}

	auto it=v.begin();
	for(int k=0;k<r-1;k++){
		cout<<"2 "<<it->ff<<' '<<it->ss<<' ';
		it+=1;
		cout<<it->ff<<' '<<it->ss<<'\n';
		it+=1;
	}
	cout<<v.end()-it<<' ';
	while(it!=v.end()){
		cout<<it->ff<<' '<<it->ss<<' ';
		it+=1;
	}
}