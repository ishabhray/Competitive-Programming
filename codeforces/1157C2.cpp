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
	vi l,r;
	l.pb(a[0]);
	r.pb(a[n-1]);
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1])
			l.pb(a[i]);
		else
			break;
	}
	for(int i=n-2;i>=0;i--){
		if(a[i]>a[i+1])
			r.pb(a[i]);
		else
			break;
	}
	int pre=0;
	string s="";
	int i=0,j=0;
	while(1){
		if(s.size()==n||i==l.size()||j==r.size())
			break;
		if(l[i]<r[j]&&l[i]>pre){
			pre=l[i];
			s+='L';
			i++;
		}
		else if(r[j]<l[i]&&r[j]>pre){
			pre=r[j];
			s+='R';
			j++;
		}
		else if(l[i]==r[j]&&l[i]>pre){
			if(l.size()-i>=r.size()-j){
				for(int k=0;k<l.size()-i;k++)
					s+='L';
				pre=l[l.size()-1];
			}
			else{
				for(int k=0;k<r.size()-j;k++)
					s+='R';
				pre=r[r.size()-1];
			}
			break;
		}
		else break;
	}
	if(i==l.size()&&j<r.size()&&r[j]>pre){
		while(j<r.size())
			s+='R',j++;
	}
	if(j==r.size()&&i<l.size()&&l[i]>pre){
		while(i<l.size())
			s+='L',i++;
	}
	cout<<s.size()<<'\n'<<s;
}