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

	string s;
	int a,b;
	cin>>s>>a>>b;
	int n=s.size(),x[n]={0},y[n]={0};
	x[0]=(s[0]-48)%a;
	for(int i=1;i<n;i++){
		x[i]=(s[i]-48+x[i-1]*10)%a;
	}
	y[n-1]=(s[n-1]-48)%b;
	for(int i=n-2;i>=0;i--){
		y[i]=((s[i]-48)*exp(10,n-i-1,b)+y[i+1])%b;
	}
	int i;
	for(i=1;i<n;i++){
		if(s[i]!='0'&&x[i-1]==0&&y[i]==0)
			break;
	}
	if(i==n)
		cout<<"NO";
	else{
		cout<<"YES\n";
		for(int j=0;j<n;j++){
			if(j==i)
				cout<<'\n';
			cout<<s[j];
		}
	}
}