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
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int c=0;
		bool b=true;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				if(c==0 || c>=6)
					c=1;
				else{
					b=false;
					break;
				}
			}
			else if(c!=0)
				c++;
		}
		if(b)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}