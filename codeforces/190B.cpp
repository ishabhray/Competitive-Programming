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

	int r,x,y,a,b,c;
	cin>>x>>y>>r>>a>>b>>c;
	double d=sqrt(pow(a-x,2)+pow(b-y,2));
	if(d>r+c)
		cout<<setprecision(20)<<(d-r-c)/2.0;
	else if(d<abs(r-c))
		cout<<setprecision(20)<<(abs(r-c)-d)/2.0;
	else
		cout<<setprecision(20)<<0.0;
}