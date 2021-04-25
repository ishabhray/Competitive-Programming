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

	int n;
	cin>>n;
	if(n<4)
		cout<<"NO";
	else if(n%2==0){
		cout<<"YES\n1 + 2 = 3\n3 + 3 = 6\n6 * 4 = 24\n";
		for(int i=5;i<=n;i+=2)
			cout<<i+1<<" - "<<i<<" = 1\n24 * 1 = 24\n";
	}
	else{
		cout<<"YES\n2 * 4 = 8\n3 * 5 = 15\n8 + 15 = 23\n23 + 1 = 24\n";
		for(int i=6;i<=n;i+=2)
			cout<<i+1<<" - "<<i<<" = 1\n24 * 1 = 24\n";
	}
}