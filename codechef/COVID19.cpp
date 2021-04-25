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
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int min=9,max=0,c=1;
		for(int i=1;i<n;i++){
			if(a[i]-a[i-1]<=2)
				c++;
			else{
				max=(c>max)?c:max;
				min=(c<min)?c:min;
				c=1;
			}
		}
		max=(c>max)?c:max;
		min=(c<min)?c:min;
		cout<<min<<' '<<max<<'\n';
	}
}