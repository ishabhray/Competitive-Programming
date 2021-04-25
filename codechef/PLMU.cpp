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
		int n;
		cin>>n;
		int x=0,y=0;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			if(a==0)
				x++;
			else if(a==2)
				y++;				
		}
		int c=x*(x-1)/2 + y*(y-1)/2;
		cout<<c<<'\n';
	}
}