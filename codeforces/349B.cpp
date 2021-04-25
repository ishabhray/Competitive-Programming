#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int v;
	cin>>v;
	map<int,int>m;
	for(int i=0;i<9;i++){
		int x;
		cin>>x;
		m[x]=i+1;
	}
	if(v<m.begin()->first)
		cout<<"-1\n";
	else{
		int j=v/m.begin()->first;
		string s="";
		for(int k=0;k<j;k++)
			s.push_back(m.begin()->second+48);
		int i=v%m.begin()->first;
		int l=0;
		while(i>0){
			int max=0,maxi=0;
			for(int k=m.begin()->first;k<=m.begin()->first+i;k++){
				if(m[k]>max)
					max=m[k],maxi=k-m.begin()->first;
			}
			if(max==m.begin()->second)
				break;
			s[l++]=max+48;
			i-=maxi;
		}
		cout<<s;
	}
}