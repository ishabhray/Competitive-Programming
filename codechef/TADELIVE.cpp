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

	int n,x,y;
	cin>>n>>x>>y;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll sum=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		sum+=a[i];
		a[i]-=x;
	}
	sort(a,a+n);
	
	for(int i=0;i<n;i++){
		if(a[i]<=0&&y>0){
			sum-=a[i];
			y--;
		}
		else if(a[i]<=0&&y==0){
			//sum+=a[i];
			x--;
			break;
		}
		else if(a[i]>0&&x>=n-i){
			//sum+=a[i];
			x--;
			break;
		}
		else{
			sum-=a[i];
			y--;
		}
		//cout<<x<<' '<<y<<' '<<sum<<'\n';
	}
	cout<<sum<<'\n';
}