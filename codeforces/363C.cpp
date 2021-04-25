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

	string s,r="",t="";
	cin>>s;
	int n=s.size();
	if(n<=2)
		cout<<s;
	else{
		r+=s[0];
		r+=s[1];
		for(int i=2;i<n;i++){
			if(s[i]!=s[i-1]||s[i]!=s[i-2])
				r+=s[i];
		}
		n=r.size();
		if(n<=3)
			cout<<r;
		else{
			t+=r[0];
			t+=r[1];
			t+=r[2];
			for(int i=3;i<n;i++){
				int m=t.size();
				if(t[m-1]==r[i]&&t[m-2]==t[m-3])
					continue;
				t+=r[i];
			}
			cout<<t;
		}
	}
	
}