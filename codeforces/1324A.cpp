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
		int max=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]>max)
				max=a[i];
		}
		bool b=true;
		for(int i=0;i<n;i++){
			if((max-a[i])%2!=0){
				b=false;
				break;
			}
		}
		if(b)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}