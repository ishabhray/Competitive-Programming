#include <bits/stdc++.h>
using namespace std;

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

	int T;
	cin>>T;
	while(T--){
		int h,c,t;
		cin>>h>>c>>t;
		if(t<=(h+c)/2)
			cout<<"2\n";
		else{
			ld n=(ld)(h-t)/(ld)(2*t-h-c);
			ll a=(ll)ceill(n),b=a-1;
			ld t1=(ld)((a+1)*h+a*c)/(ld)(2*a+1);
			ld t2=(ld)((b+1)*h+b*c)/(ld)(2*b+1);
			if(abs(t1-t)<abs(t2-t))
				cout<<2*a+1<<'\n';
			else
				cout<<2*b+1<<'\n';
		}
	}
}