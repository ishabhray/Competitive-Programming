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

int exp(int a,int b,int c)//finds a^b%c
{
	if(b==0)
		return 1;
	else{
		ll x=exp(a,b/2,c);
		x*=x;
		x=x%c;
		if(b%2==0)
			return x;
		else{
			x*=a;
			x=x%c;
			return x;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int p;
	cin>>p;
	int cnt=0;
	for(int x=2;x<p;x++){
		if((x-1)%p==0)
			continue;
		int s=1,j;
		bool b=false;
		for(j=1;j<p-1;j++){
			s=(s+exp(x,j,p))%p;
			if(s==0){
				b=true;
				break;
			}
		}
		if(b&&j==p-2)
			cnt++;
	}
	if(p==2)
		cout<<1;
	else
		cout<<cnt;
}