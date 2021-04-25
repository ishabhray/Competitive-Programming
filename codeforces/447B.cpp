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

	string s;
	int k;
	cin>>s>>k;
	map<char,int>m;
	int max=-1,n=s.size();
	for(char i='a';i<='z';i++){
		cin>>m[i];
		if(m[i]>max)
			max=m[i];
	}
	ll sum=0;
	for(int i=0;i<n;i++)
		sum+=(i+1)*m[s[i]];
	for(int i=0;i<k;i++)
		sum+=(n+1+i)*max;
	cout<<sum;
}