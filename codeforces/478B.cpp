#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,m;
	cin>>n>>m;
	long long int max=(long long)(n-m+1)*(n-m)/2;
	long long int min=(long long)(n%m)*(n/m+1)*(n/m)/2+(long long)(m-n%m)*(n/m-1)*(n/m)/2;
	cout<<min<<' '<<max;
}