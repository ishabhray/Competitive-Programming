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

	int n;
	cin>>n;
	stack<int>s;
	while(n>=7){
		s.push(7);
		n-=7;
	}
	int c=0;
	if(n>=4)
		c++,n-=4;
	if(n>s.size())
		cout<<"-1";
	else{
		for(int i=1;i<=n;i++){
			s.pop();
			c+=2;
		}
		for(int i=0;i<c;i++)
			s.push(4);
		while(!s.empty()){
			cout<<s.top();
			s.pop();
		}
	}
}