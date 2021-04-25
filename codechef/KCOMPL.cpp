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
		int n,k,c=0;
		cin>>n>>k;
		string s;
		cin>>s;
		for(int i=0;i<(k+1)/2;i++){
			int a[26]={0},b=0;
			for(int j=0;j<n/k;j++){
				int x=j*k+i;
				a[s[x]-97]++,b++;
				int y=(j+1)*k-1-i;
				if(y!=x)
					a[s[y]-97]++,b++;
			}
			int max=0;
			for(int j=0;j<26;j++){
				if(a[j]>max)
					max=a[j];
			}
			c+=(b-max);
		}
		cout<<c<<'\n';
	}
}