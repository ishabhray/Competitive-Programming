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
		string s;
		cin>>s;
		int max=0,c=0,i;
		for(i=0;i<s.size();i++){
			if(s[i]=='L')
				c++;
			else{
				max=(max>c)?max:c;
				c=0;
			}
		}
		max=(max>c)?max:c;
		cout<<max+1<<"\n";
	}
}