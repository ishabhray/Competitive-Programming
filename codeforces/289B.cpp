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

	int n,m,d;
	cin>>n>>m>>d;
	int a[n][m];
	int x=-1;
	bool b=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int y;
			cin>>y;
			a[i][j]=y/d;
			if(x==-1)
				x=y%d;
			else if(x!=y%d)
				b=false;
		}
	}
	if(b){
		int z[n*m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				z[i*m+j]=a[i][j];
		sort(z,z+n*m);
		int median=z[n*m/2],cnt=0;
		for(int i=0;i<n*m;i++)
			cnt+=abs(median-z[i]);
		cout<<cnt;
	}
	else
		cout<<-1;
}