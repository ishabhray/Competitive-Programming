#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

bool isprime(int n){
	int c=0;
	for(int i=1;i<=sqrt(n);i++)
		if(n%i==0)
			c++;
	return c==1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1)
			cout<<"FastestFinger\n";
		else if(n%2)
			cout<<"Ashishgup\n";
		else if(n==2)
			cout<<"Ashishgup\n";
		else if(ceil(log2(n)) == floor(log2(n))||((n/2)%2)&&isprime(n/2))
			cout<<"FastestFinger\n";
		else
			cout<<"Ashishgup\n";
	}
}