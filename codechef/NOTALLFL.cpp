#include <bits/stdc++.h>
using namespace std;

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
		int n,k;
		cin>>n>>k;
		map<int,int> m;
		vector<pair<int,int> >v;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(v.empty()||(v.end()-1)->f!=x)
				v.pb({x,1});
			else
				(v.end()-1)->s++;
		}
		for(auto a:v)
			cout<<a.f<<' '<<a.s<<' ';
	}
}