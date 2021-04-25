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
		int a,b,c,d,n;
		cin>>n>>a>>b>>c>>d;
		int w=(a-b)*n,x=(a+b)*n,y=c-d,z=c+d;
		if((y>=w&&y<=x)||(z>=w&&z<=x)||(x>=y&&x<=z))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}