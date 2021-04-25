#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pint pair<int,int>
#define vv vector
#define C 1000000007

int order[4]={1,2,3,4},n;

typedef struct{
	int n,c;
}card;

bool operator<(card const& l,card const& r){
	//cout<<"$$$$ "<<l.c<<' '<<l.n<<' '<<r.c<<' '<<r.n<<' '<<((l.c!=r.c)?find(order,order+n,l.c)<find(order,order+n,r.c):l.n<r.n)<<"$$$\n";
	if(l.c!=r.c)
		return find(order,order+n,l.c)<find(order,order+n,r.c);
	else
		return l.n<r.n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int T=1;
	//cin>>T;
	while(T--){
		int c;
		cin>>n>>c;
		card a[n*c];
		for(int i=0;i<n*c;i++)
			cin>>a[i].c>>a[i].n;
		int mn=INT_MAX,cnt=1;
		do{
			//for(int i=0;i<n;i++)
			//	cout<<order[i]<<' ';
			//cout<<'\n';
			int dp[n*c];
			dp[0]=1;
			for(int i=1;i<n*c;i++){
				int mx=0;
				for(int j=0;j<i;j++){
					if(a[j]<a[i])
						mx=max(dp[j],mx);
				}
				dp[i]=1+mx;
			}
			int mx=0;
			for(int i=0;i<n*c;i++)
				mx=max(mx,dp[i]);
			//cout<<"---->"<<mx;
			//cout<<" ------->";
			//sort(a,a+n*c);
			//for(int i=0;i<n*c;i++)
			//	cout<<a[i].c<<' ';
			card x={1,1},y={2,1},z={3,1};
			//cout<<(x<y)<<' '<<(y<z);//<<' '<<(z<x);
			//cout<<'\n';
			mn=min(mn,n*c-mx);
		}while(next_permutation(order,order+n));
		
		cout<<mn<<'\n';
	}
}