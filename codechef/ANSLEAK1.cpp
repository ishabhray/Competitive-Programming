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
		int n,m,k;
		cin>>n>>m>>k;
		int kanscnt[k]={0};
		vector<map<int,vector<int> > >v(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				int x;
				cin>>x;
				v[i][x].push_back(j);
			}
		}
		vector<vector<int> >ans;
		for(int i=0;i<n;i++){
			int max=0;
			vector<int> v1;
			for(int j=1;j<=m;j++){
				if(v[i][j].size()>max){
					max=v[i][j].size();
					v1.clear();
					v1.push_back(j);
				}
				else if(v[i][j].size()==max)
					v1.push_back(j);
			}
			ans.push_back(v1);
		}
		int fans[n]={0};
		for(int i=0;i<n;i++){
			if(ans[i].size()==1){
				fans[i]=ans[i][0];
				for(auto a:v[i][fans[i]])
					kanscnt[a]++;
			}
		}
		for(int i=0;i<n;i++){
			if(fans[i]!=0)
				continue;
			int min=INT_MAX,an=0;
			for(auto a:ans[i]){
				for(auto b:v[i][a])
					if(kanscnt[b]<min)
						min=kanscnt[b],an=a;
			}
			fans[i]=an;
			for(auto a:v[i][fans[i]])
				kanscnt[a]++;
		}
		for(int i=0;i<n;i++)
			cout<<fans[i]<<' ';
		cout<<'\n';
	}
}