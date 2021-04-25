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
		int m;
		string s;
		cin>>s>>m;
		int b[m];
		char c[m];
		int x[m]={0};
		map<char,int>mp;
		for(int i=0;i<s.size();i++)
			mp[s[i]]++;
		for(int i=0;i<m;i++)
			cin>>b[i];
		int cnt=0;
		char z='z';
		while(cnt<m){
			
			vi v;
			for(int i=0;i<m;i++){
				if(b[i]==0&&x[i]==0)
					v.pb(i);
			}
			while(mp[z]<v.size())
				z--;
			for(auto a:v)
				c[a]=z,x[a]=1;
			z--;
			cnt+=v.size();
			for(int i=0;i<m;i++){
				for(auto a:v)
					b[i]-=abs(a-i);
			}
		}
		for(int i=0;i<m;i++)
			cout<<c[i];
		cout<<'\n';
	}
}