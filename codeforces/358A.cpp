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

bool check(int a1,int a2,int a3,int a4)
{
	if(a1<a3&&a3<a2&&a2<a4 || a3<a1&&a1<a4&&a4<a2)
		return true;
	else
		return false;
}

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
	bool b=false;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n-1;j++){
			if(check(min(a[i],a[i+1]),max(a[i],a[i+1]),min(a[j],a[j+1]),max(a[j],a[j+1]))){
				b=true;
				break;
			}
		}
		if(b)
			break;
	}
	
	if(b)
		cout<<"yes";
	else
		cout<<"no";
}