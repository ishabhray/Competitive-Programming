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
	int u[n],l[n];
	for(int i=0;i<n;i++){
		cin>>u[i];
		cin>>l[i];
	}
	int oe=0,su=0,sl=0;
	for(int i=0;i<n;i++){
		if(u[i]%2==0&&l[i]%2!=0)
			oe++;
		else if(u[i]%2!=0&&l[i]%2==0)
			oe++;
		su+=u[i];
		sl+=l[i];
	}
	
	if(sl%2==0&&su%2==0)
		cout<<"0";
	else if(sl%2!=0&&su%2!=0&&oe)
		cout<<1;
	else
		cout<<-1;
}