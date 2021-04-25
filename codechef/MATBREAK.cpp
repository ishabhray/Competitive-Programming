#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int c=1000000007;

int exp(int a,int b)
{
	if(b==0)
		return 1;
	else{
		ll f=exp(a,b/2);
		f*=f;
		f=f%c;
		if(b%2==0)
			return f;
		else{
			f*=a;
			f=f%c;
			return f;
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

	int t;
	cin>>t;
	while(t--){
		int n;
		ll a;
		cin>>n>>a;
		ll s=0;
		for(int i=1;i<=n;i++){
			int j=2*i-1;
			int k=exp(a,j);
			s+=k;
			s=s%c;
			a=a*k;
			a%=c;
		}
		cout<<s<<'\n';
	}
}