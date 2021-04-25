#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

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
		char a[n][m];
		char b[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>b[i][j];
		int c[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				c[i][j]=0;
		vector<pair<int,int> >w;
		vector<pair<int,int> >v;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(c[i][j]==1)
					continue;
				int x=i,y=j;
				do{
					//cout<<x<<' '<<y<<'\n';
					v.pb({x,y});
					c[x][y]=1;
					if(b[x][y]=='U')
						x-=1;
					else if(b[x][y]=='D')
						x+=1;
					else if(b[x][y]=='L')
						y-=1;
					else
						y+=1;
				}while(c[x][y]==0);
				for(auto i=v.begin();i!=v.end();i++){
					if((*i).first==x&&(*i).second==y)
						w.insert(w.end(),i,v.end());
				}
				for(auto i:w)
					//cout<<i.first<<' '<<i.second<<'\n';
				v.clear();
			}
		}
		int black=0;
		for(auto i:w){
			cout<<i.first<<' '<<i.second<<'\n';
			if(a[i.first][i.second]=='0')
				black++;
		}
		cout<<w.size()<<' '<<black<<'\n';
	}
}