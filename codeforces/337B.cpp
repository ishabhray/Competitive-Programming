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

	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==b&&c==d)cout<<"0/1";
	else if(c==d){
		int mx=max(a,b);
		int mn=min(a,b);
		cout<<mx-mn<<'/'<<mx;
	}
	else{
		if(d>c){
			d=d+c;
			c=d-c;
			d=d-c;
			b=b+a;
			a=b-a;
			b=b-a;
		}
		int g=gcd(b*c,b*c-a*d);
		cout<<(b*c-a*d)/g<<'/'<<(b*c/g);
	}
}