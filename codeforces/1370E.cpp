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
	//cin>>t;
	while(t--){
		int n;
		string s,r;
		cin>>n>>s>>r;
		int c=0,c1=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1')
				c++;
			if(r[i]=='1')
				c1++;
		}
		if(c!=c1){
			cout<<"-1";
			return 0;
		}
		string x="";
		for(int i=0;i<n;i++)
			if(s[i]!=r[i])
				x+=s[i];
		int c0=0;
		c1=0;
		n=x.size();
		for(int i=0;i<n;i++){
			if(x[i]=='1')
				c1++,c0=max(0,c0-1);
			else
				c0++,c1=max(0,c1-1);
		}
		cout<<c0+c1;
	}
}