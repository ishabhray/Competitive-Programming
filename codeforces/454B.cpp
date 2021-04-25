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
	for(int i=0;i<n;i++)
		cin>>a[i];
	int cnt=0,pos=0;
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1])
			cnt++,pos=i;
	}
	if(cnt==0)
		cout<<0;
	else if(cnt>1||a[n-1]>a[0])
		cout<<-1;
	else
		cout<<n-pos;
}