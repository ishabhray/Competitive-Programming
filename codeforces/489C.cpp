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

	int m,s;
	cin>>m>>s;
	if((s==0&&m>1)||s>9*m)
		cout<<"-1 -1";
	else if(s==0&&m==1)
		cout<<"0 0";
	else{
		string mx="",mn="";
		int t=s;
		for(int j=0;j<m;j++)
			mx+=min(9,t)+48,t-=min(9,t);
		int j;
		for(j=1;j<=9;j++)
			if(s-j<=(m-1)*9)
				break;
		mn+=j+48;
		s-=j;
		for(int k=0;k<m-1;k++){
			for(j=0;j<=9;j++)
				if(s-j<=(m-2-k)*9)
					break;
			s-=j;
			mn+=j+48;
		}
		cout<<mn<<' '<<mx;
	}
}