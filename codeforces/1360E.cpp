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
		bool b=true;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>ch[i][j];
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-1;j++){
				if(ch[i][j]=='1'&&ch[i][j+1]=='0'&&ch[i+1][j]=='0'){
					b=false;
					break;
				}
			}
			if(!b)
				break;
		}
		if(b)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}