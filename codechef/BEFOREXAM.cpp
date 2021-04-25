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

	int d,s;
	cin>>d>>s;
	int min[d],max[d];
	for(int i=0;i<d;i++){
		int x,y;
		cin>>x>>y;
		min[i]=x,max[i]=y;
		if(i!=0)
			min[i]+=min[i-1],max[i]+=max[i-1];
	}
	if(s>=min[d-1]&&s<=max[d-1]){
		cout<<"YES\n";
		for(int i=0;i<d;i++){
			int min1=0;
			int max1=0;
			if(i!=0)
				min1=min[i-1],max1=max[i-1];
			for(int j=min[i]-min1;j<=max[i]-max1;j++){
				if(s-j>=min[d-1]-min[i]&&s-j<=max[d-1]-max[i]){
					cout<<j<<' ';
					s-=j;
					break;
				}
			}
		}
	}
	else
		cout<<"NO\n";
}