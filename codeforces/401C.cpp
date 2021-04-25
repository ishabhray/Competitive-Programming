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

	int n,m;
	cin>>n>>m;
	if(n>m+1||(m+1)/2>n+1)
		cout<<"-1";
	else{
		string s="";
		if(n>m)
			s+="0",n--;
		while(n>0){
			if(m>n)
				m-=2,n--,s+="110";
			else
				m--,n--,s+="10";
		}
		for(int i=0;i<m;i++)
			s+="1";
		cout<<s;
	}
}