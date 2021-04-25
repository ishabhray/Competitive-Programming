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
		int n;
		cin>>n;
		int p[]={2,3,5,7,11,13,17,19,23,29,31};
		int m[11]={0};
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			for(int j=0;j<11;j++)
				if(a[i]%p[j]==0){
					m[j]++;
					break;
				}
		}
		int s=0;
		for(int j=0;j<11;j++){
			if(m[j]!=0){
				s++;
				for(int i=0;i<n;i++)
					if(a[i]%p[j]==0)
						a[i]=s;
			}
		}
		cout<<s<<'\n';
		for(int i=0;i<n;i++)
			cout<<a[i]<<' ';
		cout<<'\n';
	}
}
