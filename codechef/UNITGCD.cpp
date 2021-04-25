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
		if(n==1){
			cout<<"1\n1 1\n";
			continue;
		}
		int d=n/2;
		cout<<d<<'\n';
		for(int i=0;i<d-1;i++)
			cout<<"2 "<<2*i+1<<' '<<2*i+2<<'\n';
		if(n%2==0)
			cout<<"2 "<<n-1<<' '<<n<<'\n';
		else
			cout<<"3 "<<n-2<<' '<<n-1<<' '<<n<<'\n';
	}
}