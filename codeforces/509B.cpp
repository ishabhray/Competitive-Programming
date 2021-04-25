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

	int n,k;
	cin>>n>>k;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	int cnt=0;
	for(int i=1;i<n;i++)
		cnt+=b[i]-b[i-1];
	if(cnt>k)
		cout<<"NO";
	else{
		cout<<"YES\n";
		for(int i=0;i<n;i++){
			for(int j=1;j<=a[i];j++)
				cout<<max(1,j-b[0])<<' ';
			cout<<'\n';
		}
	}
}