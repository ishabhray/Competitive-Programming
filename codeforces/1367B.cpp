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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int x=0,y=0;
		for(int i=0;i<n;i++){
			if(i%2==a[i]%2){
				continue;
			}
			if(i%2==0)
				x++;
			else
				y++;
		}
		//cout<<x<<' '<<y<<' ';
		if(x==y)
			cout<<x<<'\n';
		else
			cout<<"-1\n";
	}
}