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

int gcd(int a,int b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int r,c,x,y;
	cin>>r>>c>>x>>y;
	if(r==x||c==y)
		cout<<"1 ";
	else
		cout<<"2 ";
	if((r+c)%2!=(x+y)%2)
		cout<<"0 ";
	else if(r+c==x+y || r-c==x-y)
		cout<<"1 ";
	else
		cout<<"2 ";
	int step=0;
	while(r!=x||c!=y){
		if(x>r)
			r++;
		else if(x<r)
			r--;
		if(y>c)
			c++;
		else if(y<c)
			c--;
		step++;
	}
	cout<<step;
}