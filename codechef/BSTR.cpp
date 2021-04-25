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
	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int i=1,s=1;
		while(k>s){
			i++;
			s+=i;
		}
		int i1=k-(s-i)-1;
		for(int j=0;j<n;j++){
			if(j==n-1-i||j==n-1-i1)
				cout<<'b';
			else
				cout<<'a';
		}
		cout<<'\n';
	}
}