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
	int a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	ll x[2*n-1]={0},y[2*n-1]={0};
	for(int k=0;k<2*n-1;k++){
		for(int i=0;i<n;i++){
			if(k-i<n&&k-i>=0){
				x[k]+=a[i][k-i];
			}
		}
	}
	for(int k=-(n-1);k<=n-1;k++){
		for(int i=0;i<n;i++){
			if(i+k>=0&&i+k<n)
				y[k+n-1]+=a[i][i+k];
		}
	}
	ll max1=-1,max2=-1;
	int i1,i2,j1,j2;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ll sum=x[i+j]+y[j-i+n-1]-a[i][j];
			if((i+j)%2==0){
				if(sum>max1)
					max1=sum,i1=i,j1=j;
			}
			else{
				if(sum>max2)
					max2=sum,i2=i,j2=j;
			}
		}
	}
	max1+=max2;
	cout<<max1<<'\n';
	cout<<i1+1<<' '<<j1+1<<' '<<i2+1<<' '<<j2+1;
}