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

	int t=1;
	cin>>t;
	while(t--){
		int n,k;
		string s;
		cin>>n>>k>>s;
		int cnt=0;
		for(int i=0;i<n;i++)
			if(s[i]=='1')
				cnt++;
		int ans=cnt;
		for(int i=0;i<k;i++){
			int c=0;
			for(int j=i;j<n;j+=k){
				if(s[j]=='1')
					c++;
				else c--;
				c=max(0,c);
				ans=min(ans,cnt-c);
			}
		}
		cout<<ans<<'\n';
	}
}