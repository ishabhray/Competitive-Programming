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

	int n,p;
	string s;
	cin>>n>>p>>s;
	p--;
	int a[n]={0};
	for(int i=0;i<n;i++){
		char c=s[i],d=s[n-1-i];
		a[i]=min(abs(c-d),26-abs(c-d));
	}
	int l=-1,r=-1,sum=0;
	for(int i=0;i<(n+1)/2;i++){
		sum+=a[i];
		if(a[i]!=0){
			r=i;
			if(l==-1)
				l=i;
		}
	}
	if(p>=n/2)
		p=n-1-p;
	//for(int i=0;i<n;i++)
	//	cout<<a[i]<<' ';
	//cout<<'\n'<<l<<' '<<r<<' '<<p<<' '<<sum<<'\n';
	if(sum==0)
		cout<<sum;
	else
		cout<<sum+r-l+min(abs(r-p),abs(p-l));
}