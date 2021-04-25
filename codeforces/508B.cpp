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
	cin>>s;
	int n=s.size(),j=-1;
	for(int i=n-2;i>=0;i--){
		if((s[i]-48)%2==0){
			if(j==-1||s[n-1]>s[i])
				j=i;
		}
	}
	if(j==-1)
		cout<<j;
	else{
		char ch=s[n-1];
		s[n-1]=s[j];
		s[j]=ch;
		cout<<s;
	}
}