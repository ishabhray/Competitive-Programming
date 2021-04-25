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
		ld n;
		cin>>n;
		n/=2;
		ld ans=0,j=90/n,k=j;
		for(int i=0;i<n;i++){
			ans+=sin(k*PI/180.0);
			//cout<<k<<' '<<ans<<'\n';
			k+=j;
		}
		cout<<setprecision(12)<<2*ans-1<<'\n';
	}
}