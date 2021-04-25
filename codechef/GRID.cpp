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

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		char ch[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>ch[i][j];
		int a[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=0;
		for(int i=0;i<n;i++){
			for(int j=n-1;j>=0;j--){
				if(ch[j][i]=='#')
					break;
				a[j][i]++;
			}
			for(int j=n-1;j>=0;j--){
				if(ch[i][j]=='#')
					break;
				a[i][j]++;
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				//cout<<a[i][j]<<' ';
				if(a[i][j]==2)
					cnt++;
			}
			//cout<<'\n';
		}
		cout<<cnt<<'\n';
	}
}