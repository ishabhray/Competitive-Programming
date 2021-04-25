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
	int n=s.size();
	int c4=0,c7=0;
	for(int i=0;i<n;i++){
		if(s[i]=='4')
			c4++;
		else if(s[i]=='7')
			c7++;
	}
	if(c4+c7==0)
		cout<<-1;
	else if(c4>=c7)
		cout<<4;
	else
		cout<<7;
}