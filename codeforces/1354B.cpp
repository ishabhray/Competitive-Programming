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
		string s;
		cin>>s;
		int n=s.size();
		int start=0,cnt=1,end=0,ans=INT_MAX;
		for(int i=1;i<n-1;i++){
			if(s[i]==s[i-1])
				cnt++,end=i;
			else
				start=i,cnt=1,end=i;
			if(start!=0&&s[start-1]!=s[start]&&s[end+1]!=s[end]&&s[start-1]!=s[end+1])
				ans=min(ans,end-start+3);
			//cout<<start<<' '<<cnt<<' '<<end<<' '<<ans<<'\n';
		}
		cout<<((ans==INT_MAX)?0:ans)<<'\n';
	}
}