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

	int t,c=0;
	cin>>t;
	int a[t]={0};
	a[0]=1;
	for(int i=2;i*i<=t;i++){
		if(a[i-1]==0){
			c++;
			for(int j=i*i;j<=t;j+=i)
				a[j-1]=1;
		}
	}
	cout<<c;
}