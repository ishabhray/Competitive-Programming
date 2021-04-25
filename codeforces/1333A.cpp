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
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<m;j++){
				if((i+j)%2==0)
					cout<<'B';
				else
					cout<<'W';
			}
			cout<<'\n';
		}
		
		if((n*m)%2==0){
			if(n%2==0){
				cout<<'B';
				for(int j=0;j<m-1;j++){
					if(j%2==0)
						cout<<'B';
					else
						cout<<'W';
				}
			}
			else{
				for(int j=0;j<m-1;j++){
					if(j%2==0)
						cout<<'B';
					else
						cout<<'W';
				}
				cout<<'B';
			}
		}
		else{
			for(int j=0;j<m;j++){
				if(j%2==0)
					cout<<'B';
				else
					cout<<'W';
			}
		}
		cout<<'\n';
	}
}