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

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int i=0,j=n-1,pre=0;
	string s="";
	while(1){
		if(i>j)
			break;
		if(a[i]<pre&&a[j]<pre)
			break;
		if(a[i]<pre)
			s+='R',pre=a[j],j--;
		else if(a[j]<pre)
			s+='L',pre=a[i],i++;
		else if(a[i]<a[j])
			s+='L',pre=a[i],i++;
		else
			s+='R',pre=a[j],j--;
		if(i==j){
			if(a[i]>pre)
				s+='L';
			break;
		}
	}
	cout<<s.size()<<'\n'<<s<<'\n';
}