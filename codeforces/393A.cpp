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

	string s;
	cin>>s;
	map<char,int>m;
	for(int i=0;i<s.size();i++){
		if(s[i]=='n'||s[i]=='i'||s[i]=='e'||s[i]=='t')
			m[s[i]]++;
	}
	//cout<<m['n']<<' '<<m['i']<<' '<<m['e']<<' '<<m['t']<<'\n';
	cout<<min(min((m['n']-1)/2,m['i']),min(m['e']/3,m['t']));
}