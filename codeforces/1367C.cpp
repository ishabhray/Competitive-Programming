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
		int cnt=0;
		int dis=-1;
		for(int i=0;i<n;i++){
			if(s[i]=='1')
				i+=k;
			else{
				bool b=true;
				for(int j=1;j<=k&&i+j<n;j++){
					if(s[i+j]=='1'){
						i+=j+k;
						b=false;
						break;
					}
					//else if(s[i-j]=='1'){
					//	b=false;
					//	break;
					//}
				}
				if(b){
					//cout<<i<<' ';
					cnt++;
					i+=k;
				}
			}
		}
		//cout<<'\n';
		cout<<cnt<<'\n';
	}
}