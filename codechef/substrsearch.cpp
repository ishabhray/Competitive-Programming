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

	map<int,char>m;
	for(int i=1;i<=26;i++){
		int x;
		cin>>x;
		m[i]=96+x;
	}
	string s,t;
	cin>>s>>t;
	for(int i=0;i<t.size()-s.size()+1;i++){
		int z=1;
		for(int j=0;j<s.size();j++){
			if(t[i+j]!=s[j]&&t[i+j]!=m[s[j]-96]){
				z=0;
				break;
			}
		}
		cout<<z;
	}
}