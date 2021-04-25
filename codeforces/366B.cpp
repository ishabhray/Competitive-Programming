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

	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int mn=INT_MAX,pos=-1;
	for(int i=0;i<k;i++){
		int s=0;
		bool f=true;
		int j=i;
		while(f||j<i){
			s+=a[j];
			j+=k;
			if(j>=n)
				j=j%n,f=false;
		}
		if(s<mn)
			mn=s,pos=i;
	}
	cout<<pos+1;
}