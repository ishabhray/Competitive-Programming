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

	ll n,m;
	cin>>n>>m;
	ll a[m];
	for(int i=0;i<m;i++)
		cin>>a[i];
	sort(a,a+m);
	if(a[0]==1||a[m-1]==n)
		cout<<"NO";
	else{
		bool b=true;
		for(int i=0;i<m-2;i++){
			if(a[i]+1==a[i+1]&&a[i]+2==a[i+2]){
				b=false;
				break;
			}
		}
		if(b)
			cout<<"YES";
		else
			cout<<"NO";
	}
}