#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

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
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				char x;
				cin>>x;
				if(x!='9')
					cout<<x;
				else
					cout<<'1';
			}
			cout<<'\n';
		}
	}
}