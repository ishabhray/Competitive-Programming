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

	int p,q,l,r;
	cin>>p>>q>>l>>r;
	int x[1001]={0},z[1001]={0};
	for(int i=0;i<p;i++){
		int a,b;
		cin>>a>>b;
		for(int j=a;j<=b;j++)
			z[j]=1;
	}
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		for(int j=a;j<=b;j++)
			x[j]=1;
	}
	int cnt=0;
	for(int i=l;i<=r;i++){
		for(int j=0;j+i<=1000;j++){
			if(x[j]==1&&z[j+i]==1){
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
}