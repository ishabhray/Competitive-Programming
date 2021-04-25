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

	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i];
	int s=0;
	char c[n];
	for(int i=0;i<n;i++){
		if(s+a[i]<=500)
			s+=a[i],c[i]='A';
		else
			s-=b[i],c[i]='G';
	}
	for(int i=0;i<n;i++)
		cout<<c[i];
}