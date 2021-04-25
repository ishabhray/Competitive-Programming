#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

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
		string a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int max=0,idx=0;
		for(int i=1;i<n;i++){
			int c=0;
			for(int j=0;j<m;j++)
				if(a[0][j]!=a[i][j])
					c++;
			if(c>max)
				max=c,idx=i;
		}
		if(max>2)
			cout<<"-1\n";
		else if(max<2)
			cout<<a[0]<<'\n';
		else{
			string s1,s2;
			bool b=true;
			for(int i=0;i<m;i++){
				if(a[0][i]==a[idx][i])
					s1+=a[0][i],s2+=a[0][i];
				else if(b){
					s1+=a[0][i],s2+=a[idx][i];
					b=false;
				}
				else
					s1+=a[idx][i],s2+=a[0][i];
			}
			bool b1=true,b2=true;
			for(int i=1;i<n;i++){
				if(i==idx)
					continue;
				int c1=0,c2=0;
				for(int j=0;j<m;j++){
					if(a[i][j]!=s1[j])
						c1++;
					if(a[i][j]!=s2[j])
						c2++;
				}
				if(c1>=2)
					b1=false;
				if(c2>=2)
					b2=false;
			}
			if(b1)
				cout<<s1<<'\n';
			else if(b2)
				cout<<s2<<'\n';
			else
				cout<<"-1\n";
		}
	}
}