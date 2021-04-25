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

int gcd(int a,int b){return (b)?gcd(b,a%b):a;}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int s,l;
	cin>>s>>l;
	map<int,vi >m;
	for(int i=1;i<=l;i++){
		int a=i&(-i);
		m[a].pb(i);
	}
	vi v;
	for(auto it=m.rbegin();it!=m.rend();it++){
		while(s>=it->ff&&!(it->ss.empty())){
			s-=it->ff;
			v.pb(it->ss.back());
			it->ss.pop_back();
		}
	}
	if(s!=0)
		cout<<-1;
	else{
		cout<<v.size()<<'\n';
		for(auto a:v)
			cout<<a<<' ';
	}
}