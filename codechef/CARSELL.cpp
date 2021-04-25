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
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(v.rbegin(),v.rend());
		long long int s=0;
		int c=0;
		for(int i=0;i<n;i++){
			if(v[i]-c>0){
				s=(s+(v[i]-c)%1000000007)%1000000007;
				c++;
			}
			else
				break;
		}
		cout<<s<<'\n';
	}
}