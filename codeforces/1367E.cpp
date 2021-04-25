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
		int n,k;
		string s;
		cin>>n>>k>>s;
		int freq[26]={0};
		for(int i=0;i<n;i++)
			freq[s[i]-'a']++;
		int ans=1;

		for(int i=2;i<=n;i++){
			int vis[i]={0};
			priority_queue<int>q;
			for(int j=0;j<26;j++)
				q.push(freq[j]);
			bool b=true;
			for(int j=0;j<i;j++){
				if(vis[j])
					continue;
				int x=j,cnt=0;
				while(!vis[x]){
					vis[x]=1;
					cnt++;
					x=(x+k)%i;
				}
				if(cnt>q.top()){
					b=false;
					break;
				}
				else{
					int y=q.top();
					q.pop();
					q.push(y-cnt);
				}
			}
			if(b)
				ans=i;
		}
		cout<<ans<<'\n';
	}
}