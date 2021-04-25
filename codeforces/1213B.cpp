#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int ans=0,mn=INT_MAX;
		for(int i=n-1;i>=0;i--){
			if(a[i]>mn)
				ans++;
			else
				mn=a[i];
		}
		cout<<ans<<'\n';
	}
}