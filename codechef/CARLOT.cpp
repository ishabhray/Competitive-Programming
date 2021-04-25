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
		int m,n;
		cin>>m>>n;
		vector < pair <int,int> > v;
		for(int i=0;i<m;i++){
			int l=-1,r=-1;
			for(int j=0;j<n;j++){
				char ch;
				cin>>ch;
				if(ch=='P'){
					if(l==-1)
						l=j;
					else
						r=j;
				}
			}
			if(l!=-1){
				if(r!=-1){
					if(i%2==0)
						v.push_back({i,l}),v.push_back({i,r});
					else
						v.push_back({i,r}),v.push_back({i,l});
				}
				else
					v.push_back({i,l});
			}
		}
		int c=0;
		if(!v.empty())
			for(auto i=v.begin();i<v.end()-1;i++)
				c+=abs(i->second-(i+1)->second)+(i+1)->first - i->first;
		cout<<c<<'\n';
	}
}
