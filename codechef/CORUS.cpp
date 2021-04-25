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
		int n,q;
		string s;
		cin>>n>>q>>s;
		map<char,int> m;
		for(int i=0;i<n;i++){
			m[s[i]]++;
		}
		for(int i=0;i<q;i++){
			int c,cnt=0;
			cin>>c;
			for(int i=0;i<26;i++){
				if(m[97+i]>c)
					cnt+=m[97+i]-c;
			}
			cout<<cnt<<'\n';
		}
	}
}