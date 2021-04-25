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

	int n;
	cin>>n;
	int a[n+1];
	a[0]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a,a+n+1);
	int idx=-1;
	for(int i=0;i<=n;i++){
		if(a[i]!=i){
			idx=i;
			break;
		}
	}
	if(idx==-1)
		idx=n+1;
	cout<<idx;
}