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
		int n,d;
		string s;
		cin>>n>>s>>d;
		int p[d];
		for(int i=0;i<d;i++)
			cin>>p[i];
		for(int i=0;i<d;i++){
			if(s[p[i]-1]=='0')
				s[p[i]-1]='2';
			else
				s[p[i]-1]='3';
			//cout<<s<<'\n';
			for(int j=0;j<n;j++){
				if(j!=0 && s[j]=='1'){
					if(s[j-1]=='0')
						s[j-1]='1';
					else if(s[j-1]=='2')
						s[j-1]='3';
				}
				if(j!=n-1 && (s[j]=='1'||s[j]=='3') && s[j+1]=='0')
					s[j+1]='1',j++;
			}
			//cout<<s<<'\n';
		}
		int x=0;
		for(int j=0;j<n;j++)
			if(s[j]=='1'||s[j]=='3')
				x++;
		cout<<x<<'\n';
	}
}