#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,x;
	string s;
	cin>>n>>x>>s;
	for(int i=0;i<x;i++){
		for(int j=0;j<n-1;j++){
			if(s[j]=='B'&&s[j+1]=='G')
				s[j]='G',s[j+1]='B',j++;
		}
	}
	cout<<s<<'\n';
}