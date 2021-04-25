#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pint pair<int,int>
#define vv vector
#define C 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,m;
	cin>>n>>m;
	int a[n][m],b[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	set <int> r,c;
	for(int i=0;i<n;i++){
		bool f=true;
		for(int j=0;j<m;j++){
			if(a[i][j]==0){
				f=false;
				break;
			}
		}
		if(f)
			r.insert(i);
	}
	for(int i=0;i<m;i++){
		bool f=true;
		for(int j=0;j<n;j++){
			if(a[j][i]==0){
				f=false;
				break;
			}
		}
		if(f)
			c.insert(i);
	}
	//for(auto a:r)
	//	cout<<a<<' ';
	//cout<<'\n';
	//for(auto a:c)
	//	cout<<a<<' ';
	//cout<<'\n';
	bool x=true;
	if((r.size()==0)^(c.size()==0))
		x=false;
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==0)
					b[i][j]=0;
				else{
					bool r1=r.find(i)!=r.end();
					bool c1=c.find(j)!=c.end();
					if(r1&&c1)
						b[i][j]=1;
					else if(a[i][j]==1&&(r1||c1))
						b[i][j]=0;
					else{
						x=false;
						break;
					}
				}
			}
			if(!x)
				break;
		}
	}
	
	if(x){
		cout<<"YES\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<b[i][j]<<' ';
		cout<<'\n';
	}}
	else
		cout<<"NO";
}