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
#define M_PI       3.14159265358979323846

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
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,greater<int>());
	ll sum=0;
	for(int i=0;i<n;i+=2)
		sum+=(i==n-1)? a[i]*a[i]:a[i]*a[i]-a[i+1]*a[i+1];
	long double area=M_PI*sum;
	cout<<setprecision(11)<<area;
}