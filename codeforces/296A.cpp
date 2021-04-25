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
	int a[n];
	map<int,int>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m[a[i]]++;
	}
	int max=0;
	for(auto it:m){
		if(it.ss>max)
			max=it.ss;
	}
	if(max<=(n+1)/2)
		cout<<"YES";
	else
		cout<<"NO";
}