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

	int n,m;
	cin>>n>>m;
	char ch[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>ch[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ch[i][j]=='-')
				cout<<'-';
			else if((i+j)%2==0)
				cout<<'B';
			else
				cout<<'W';
		}
		cout<<'\n';
	}
}