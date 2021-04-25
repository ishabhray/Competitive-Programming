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
		int x,k;
		cin>>x>>k;
		if(x==1)
			cout<<"0\n";
		else if(k==1)
			cout<<"1\n";
		else{
			int cnt=0;
			while(!(x%2)){
				x >>=1;
				cnt++;
			}
			for(int i=3; i<=sqrt(x); i++){
				while(x%i==0){
					cnt++;
					x/=i;
				}
			}
			if(x>2)
				cnt++;
			//cout<<cnt<<' ';
			if(cnt>=k)
				cout<<"1\n";
			else
				cout<<"0\n";
		}
	}
}