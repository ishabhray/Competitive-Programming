#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n][n],c=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				if(a[i][j]==1)
					c++;
				if(i==0&&j!=0)
					a[i][j]+=a[i][j-1];
				else if(j==0&&i!=0)
					a[i][j]+=a[i-1][j];
				else if(i!=0&&j!=0)
					a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			}
		}
		
		if(c==0){
			cout<<"0\n";
			continue;
		}
		vector<pair<int,int> >v;
		int sc=sqrt(c);
		for(int i=1;i<=sc;i++){
			if(c%i==0&&i<=n&&c/i<=n){
				v.push_back({i,c/i});
				if(i!=c/i)
					v.push_back({c/i,i});
			}
		}
		if(v.empty())
			cout<<"-1\n";
		else{
			int max=0;
			for(auto x:v){
				int r=x.first,c=x.second;
				for(int i=0;i<=n-r;i++){
					for(int j=0;j<=n-c;j++){
						int sum=a[i+r-1][j+c-1];
						if(i!=0&&j!=0)
							sum+=a[i-1][j-1]-a[i-1][j+c-1]-a[i+r-1][j-1];
						else if(i!=0)
							sum-=a[i-1][j+c-1];
						else if(j!=0)
							sum-=a[i+r-1][j-1];
						if(sum>max)
							max=sum;
					}
				}
			}
			cout<<c-max<<'\n';
		}
	}
}