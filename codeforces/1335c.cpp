#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f first

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
		map<int,int>m;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			m[x]++;
		}
		int d=m.size();
		int s=0;
		for(auto i:m)
			if(i.second>s)
				s=i.second;
		if(d==1&&s==1)
			cout<<"0\n";
		else if(s<=d-1)
			cout<<s<<'\n';
		else if(s==d)
			cout<<d-1<<'\n';
		else
			cout<<d<<'\n';
	}
}