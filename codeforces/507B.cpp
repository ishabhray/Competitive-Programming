#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int r,x,y,a,b;
	cin>>r>>x>>y>>a>>b;
	double d=sqrt(pow(a-x,2)+pow(b-y,2));
	d/=2*r;
	int i=ceil(d);
	cout<<i;
}