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

	int n,m;
	cin>>n>>m;
	int min=101,mx=0,min1=101;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x<min)
			min=x;
		if(x>mx)
			mx=x;
	}
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		if(x<min1)
			min1=x;
	}
	if(mx>=min1||2*min>=min1)
		cout<<-1;
	else
		cout<<max(mx,2*min);
}