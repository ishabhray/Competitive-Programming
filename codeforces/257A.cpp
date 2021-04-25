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

	int n,m,k;
	cin>>n>>m>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,greater<int>());
	int cnt=0,s=k;
	while(s<m&&cnt<n){
		//cout<<cnt<<' '<<s<<'\n';
		s+=a[cnt]-1;
		cnt++;
	}
	if(s>=m)
		cout<<cnt;
	else
		cout<<-1;
}